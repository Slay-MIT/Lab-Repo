var textsize = 5;
var myWait = setInterval(100);
    function Running() {
        if (textsize < 51) {
            textsize = textsize + 1;
            document.getElementById("mySS").innerHTML = "Text Growing";
            document.getElementById("mySS").style.fontSize = (textsize + 'pt');
            document.getElementById("mySS").style.color = "yellow";
            clearInterval(myWait);
            myWait = setInterval(100);
        }
        else if (textsize > 5) {
            textsize = textsize - 1;
            document.getElementById("mySS").innerHTML = "Text Shrinking";
            document.getElementById("mySS").style.fontSize = (textsize + 'pt');
            document.getElementById("mySS").style.color = "aquamarine";
            clearInterval(myWait);
            myWait = setInterval(100);
        }
        
    }



