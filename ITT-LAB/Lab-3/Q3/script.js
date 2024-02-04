const input = document.getElementById("number");

function phonetrans(input){
    const num = input.value;
    if(num.length == 10){
        return "Area code: " + num.slice(0,3) + " Phone Number: " + num.slice(3);
    }
    else{
        return "Enter Valid Number"
    }
}

function handleButtonClick() {
    document.getElementById("output").innerHTML = phonetrans(input);
}

document.getElementById("enter").addEventListener("click", handleButtonClick);

input.addEventListener('keypress',(event)=>{
    if (event.key === "Enter") {
        handleButtonClick();
    }
})