const API_KEY = "a656cdba16b1ff2ad92ded8392677d7f";

// Permission Page
let myWeather = document.querySelector("[user-weather]"); 
let cityWeather = document.querySelector("[search-weather]"); 
let grantAccessBtn = document.querySelector("[grant-access]"); 

// All UIs
const commonUI = document.querySelector(".common-ui"); 
const permissionUI = document.querySelector(".grant-location-container"); 
const formUI = document.querySelector(".form-container"); 
const loadingUI = document.querySelector(".loading-container"); 
const responseUI = document.querySelector(".response-container"); 
const userTab = document.querySelector("[user-weather]"); 
const searchTab = document.querySelector("[search-weather]"); 

// Response Page
let cityName = document.querySelector("[city-name]"); 
let cloudCondt = document.querySelector("[cloud-condition]"); 
let cloudImg = document.querySelector("[cloud-img]"); 
let flag = document.querySelector("[flag]"); 
let windSpeed = document.querySelector("[windspeed]"); 
let humidity = document.querySelector("[humidity]"); 
let clouds = document.querySelector("[clouds]"); 
let temp = document.querySelector("[temp]"); 

// Search Page 
let searchCity = document.querySelector('#search-city'); 
let searchBtn = document.querySelector("[search-btn]"); 

let  currTab= responseUI; 

checkLocalStorage(); // check for local storage. 
// add eventListner
grantAccessBtn.addEventListener('click', fetchUserLocation);

searchTab.addEventListener('click', ()=>{
    addActiveClass(formUI);
}); 

userTab.addEventListener('click', ()=>{
    fetchUserLocation();
}); 


searchBtn.addEventListener('click', (e)=>{
    // console.log("ok");
    e.preventDefault(); 
    let cityName = searchCity.value; 
    if(cityName===''){
        alert("Insert city"); 
        return ; 
    }else{ 
        addActiveClass(loadingUI); 
        fetchWeather(cityName);  

    }
});

// Funtion to check is we have saved user cordianates in local Storage. 
function checkLocalStorage(){
    const userCoOrd = sessionStorage.getItem("user-coordinates"); 
    if(!userCoOrd){
        addActiveClass(permissionUI); 
    }else{
        const coordinates = JSON.parse(userCoOrd); 
        console.log(coordinates);
        fetchWeatherOfUser(coordinates);
    }
} 


// API call to get weather info of any particular place.
async function fetchWeather(city){
    try{ 
        let response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`); 
        const data = await response.json(); 
        console.log(data);
        render(data); 
        addActiveClass(formUI); 
        addResponseUI();
    }catch(e){
        alert("Didn't fetch data"); 
        addActiveClass(formUI); 
    }
}

function addResponseUI(){
    responseUI.style.display = "flex"; 
}

// API call to get weather info of User by co-ordinates.
async function fetchWeatherOfUser(coordinates){
    const {lat, lon} = coordinates;
    addActiveClass(loadingUI); 
    try{
        let response = await fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric`); 
        const data = await response.json(); 
        render(data);
        addActiveClass(responseUI);
        // console.log(data)
    }catch(e){
        alert("Didn't fetch data"); 
    }
}

function render(data) {
//    if(data?.name===null) return false; 
   cityName.innerText = data?.name; 
   flag.src = `https://flagcdn.com/144x108/${data?.sys?.country.toLowerCase()}.png`; 
   let a = data?.weather?.[0]?.icon;
   a = a.substring(0, a.length-1); 
   a= a + "d"; 
   console.log(a);
   cloudImg.src = `https://openweathermap.org/img/wn/${a}@2x.png`; 
   cloudCondt.innerText = data?.weather?.[0]?.description.toUpperCase();
   temp.innerText = data?.main?.temp; 
   humidity.innerText = data?.main?.humidity + " %"; 
   windSpeed.innerText = data?.wind?.speed + " m/s"; 
   clouds.innerText = data?.clouds?.all + " %"; 
}

// function to get own location usiong Geolocarion 
function fetchUserLocation(){
    if(navigator.geolocation){
        navigator.geolocation.getCurrentPosition(getCoOrdi); 
    }else{
        alert("Geolocation is not supported"); 
    }
}

function getCoOrdi(position){
     
    const userCoordinate = {
        lat:position.coords.latitude,
        lon:position.coords.longitude
    }
    console.log(userCoordinate.lat + " " + userCoordinate.lon); 
    sessionStorage.setItem("user-coordinates", JSON.stringify(userCoordinate)); 
    fetchWeatherOfUser(userCoordinate); 
}

// Switching of UIs & switch bg of tabs. 
function addActiveClass(NewTab){
        searchCity.value = ""; 
        currTab.style.display = "none"; 
        if(NewTab===loadingUI){
            formUI.style.display = "none"; 
            responseUI.style.display  = "none"; 
        }
        currTab = NewTab; 
        currTab.style.display = "flex";
         
        if(currTab == responseUI){
            searchTab.classList.remove("active"); 
            userTab.classList.add("active"); 
        }else if(currTab == formUI){
            userTab.classList.remove("active"); 
            searchTab.classList.add("active"); 
        }
}


