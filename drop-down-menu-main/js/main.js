let btn = document.querySelector('.bar i');
let menu = document.querySelector('.menu-bar');

btn.addEventListener('click', () => {
    menu.classList.toggle('active');
    btn.classList.toggle('fa-times');
});