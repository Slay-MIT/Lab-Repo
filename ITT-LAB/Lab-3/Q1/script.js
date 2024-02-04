var textsize = 5;
var myWait = setInterval(GrowText, 100);

function GrowText() {
    if (textsize < 51) {
        textsize = textsize + 1;
        document.getElementById("mySS").innerHTML = "Text Growing";
        document.getElementById("mySS").style.fontSize = (textsize + 'pt');
        document.getElementById("mySS").style.color = "yellow";
    }
    else {
        clearInterval(myWait);
        myWait = setInterval(ShrinkText, 100);
    }
}
function ShrinkText() {
    if (textsize > 5) {
        textsize = textsize - 1;
        document.getElementById("mySS").innerHTML = "Text Shrinking";
        document.getElementById("mySS").style.fontSize = (textsize + 'pt');
        document.getElementById("mySS").style.color = "aquamarine";
    }
    else {
        clearInterval(myWait);
    }
}


