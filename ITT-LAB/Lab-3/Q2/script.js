// Function to translate each English word into Pig Latin
const out = 2
function translateToPigLatin(englishPhrase) {
    const words = englishPhrase.split(" ");

    const pigLatinWords = words.map(word => {
        if (word.length >= 2) {
            return word.slice(1) + word[0] + "ay";
        } else {
            return word;
        }
    });

    return pigLatinWords.join(" ");
}


const input = document.getElementById("textbox")

// Function to handle the button click
function handleButtonClick() {
    const textboxValue = (input).value;
    const translatedText = translateToPigLatin(textboxValue);
    (document.getElementById("pigtext")).value = translatedText;
}

// Add event listener to the "Enter" button
document.getElementById("enterbutt").addEventListener("click", handleButtonClick);


input.addEventListener('keypress',(event)=>{
    if (event.key === "Enter") {
        handleButtonClick();
    }
})


console.log(input)