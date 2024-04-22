let button = document.getElementById("check_button");

button.addEventListener("click", function() {
    console.log("Кнопка была нажата!");
    let input_email = document.getElementById("exampleInputEmail1");
    let value_email = input_email.value;
    console.log(value_email);
    let input_pass = document.getElementById("exampleInputPassword1");
    let value_pass = input_pass.value;
    console.log(value_pass);
    if (value_email == "admin@admin.com" && value_pass == "qwerty"){
        window.location.href = "./loading/loading.html";
    }
    else{
        let answer = document.querySelector(".answer");
        answer.innerHTML = 'Incorrect email or address!';
    }


});

