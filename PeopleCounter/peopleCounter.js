// People counter JS
let plus = document.querySelector('.plus'); 
let minus = document.querySelector('.minus'); 
let reset = document.querySelector('.reset'); 
let counter = document.querySelector('.counter');
var count;  

function increment(){
    count = parseInt(counter.innerText); 
    count++; 
    counter.innerText = count; 
}

function decrement(){
    count = parseInt(counter.innerText);
    count--; 
    counter.innerText = count; 
}

function resetCnt(){
    count = parseInt(counter.innerText);
    count =0; 
    counter.innerText = count; 
}

// plus.addEventListener('click', ()=>{increment()});
plus.addEventListener('click', increment);
reset.addEventListener('click', resetCnt);

