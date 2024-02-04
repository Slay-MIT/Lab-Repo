var inputElement = document.getElementById("words");
var outputArea = document.getElementById("output");

function generateWords() {
    // Get the value entered in the input box
    var words = inputElement.value.trim().toLowerCase();

    // Check if the input word is exactly five letters
    if (words.length !== 5) {
        alert("Please enter a five-letter word.");
        return;
    }

    // Generate three-letter words from the input word
    var threeLetterWords = [];

    for (var i = 0; i < words.length; i++) {
        for (var j = 0; j < words.length; j++) {
            for (var k = 0; k < words.length; k++) {
                if (i !== j && j !== k && i !== k) {
                    var outputWord = words[i] + words[j] + words[k];
                    threeLetterWords.push(outputWord);
                }
            }
        }
    }

    // Display the results in the text area
    outputArea.value = threeLetterWords.join("\n");
    return outputArea.value
}

function handleButtonClick() {
    document.getElementById("output").innerHTML = generateWords();
}

document.getElementById("enter").addEventListener("click", handleButtonClick);

input.addEventListener('keypress',(event)=>{
    if (event.key === "Enter") {
        handleButtonClick();
    }
})