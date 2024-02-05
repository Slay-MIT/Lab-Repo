function addLog(msg){
    var ul=document.getElementById("log")
    var li=document.createElement("li")
    var msg_text_node = document.createTextNode(msg)
    li.appendChild(msg_text_node)
    ul.appendChild(li)
}
function calculate(){
    expression=document.getElementById("expression").value;
    if(expression){
        try{
            answer=eval(expression);
            console.log(eval(expression));
            document.getElementById("expression").value=answer;
            addLog(expression +"="+ answer)
        }
        catch(e){
            console.log("exception occurred")
            addLog(expression + " is bad. please fix it")
        }
    }
}
function addLog(msg){
    var ul=document.getElementById("log")
    var li=document.createElement("li")
    var msg_text_node = document.createTextNode(msg)
    li.appendChild(msg_text_node)
    ul.appendChild(li)
}
function input_number(x){
    expression=document.getElementById("expression").value;
    expression=expression + x;
    document.getElementById("expression").value=expression    
}
function delete_number(){
    expression=document.getElementById("expression").value;
    expression=expression.substring(0,expression.length-1);
    document.getElementById("expression").value=expression;
}
function clearExpression() {
    document.getElementById("expression").value = "";
}

document.addEventListener("DOMContentLoaded", function() {
    // console.log(document.getElementsByClassName("btn"));
    var buttons=document.getElementsByClassName("btn");
    for (var i = 0; i < buttons.length; i++) {
        buttons[i].addEventListener("click", function() {
            this.classList.add("zoom-animation");
        });
    }
    var trailer=document.getElementById("trailer");
    // window.onmousemove=e=>{
    //     x=e.clientX-trailer.offsetWidth/2;
    //     y=e.clientY-trailer.offsetHeight/2;
    //     console.log(x,y);
    //         const keyframes = {
    //             transform :`translate(${x}px,${y}px)`
    //         }
    //         trailer.animate(keyframes , {
    //             duration : 800 ,
    //             fill: "forwards"
    //         });
    //     document.getElementById("trailer").style.transform=`translate(${x}px,${y}px)`;
    //     document.getElementById("trailer-background").style.transform=`translate(${x}px,${y}px)`;
    // }
    document.body.onmousemove=event=>{
        const{clientX,clientY}=event;
        trailer.animate({
            left:`${clientX - 25}px`,
            top:`${clientY - 25}px`
        },{duration:800,fill:"forwards"});
        // trailer_background.animate({
        //     left:` ${clientX}px`,
        //     top:`${clientY}px`
        // },{duration:700,fill:"forwards"});
    }

});

// $(".btn").click(function(event){
//     btn[i].classList.add("zoom-animation");
// });
