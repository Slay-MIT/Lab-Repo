console.log("Hello from script.js")

const circle = document.querySelector('.circle')
const text = document.querySelector('.text')
const circleX = circle.getBoundingClientRect().x
const circleY = circle.getBoundingClientRect().y
const circleWidth = circle.getBoundingClientRect().width

const circleCenterX = circleX + circleWidth / 2
const circleCenterY = circleY + circleWidth / 2
const windowMaxX = window.innerWidth
const windowMaxY = window.innerHeight

const maxDistance = Math.sqrt((windowMaxX - circleCenterX) ** 2 + (windowMaxY - circleCenterY) ** 2)
const maxFontSize = 70
const minFontSize = 15;
document.addEventListener('mousemove', (e) => {
    const x = e.clientX
    const y = e.clientY

    const distance = Math.sqrt((x - circleCenterX) ** 2 + (y - circleCenterY) ** 2)
    const factor = 1- distance / maxDistance;
    const fontSize = Math.max(maxFontSize * factor, minFontSize);

    text.style.fontSize = `${fontSize}px`
})