document.addEventListener("DOMContentLoaded", function() {
    let text = document.getElementById("for-user");
    text.innerHTML = 'Our managers are working on preparing your office for maximum productivity';

});
function next_page() {
    window.location.href = "../user-page/user.html";
}

function delayedText(){
    let text = document.getElementById("for-user");
    text.innerHTML = 'It remains to wait quite a bit';
}

setTimeout(next_page, 15000);
setTimeout(delayedText, 10000);
