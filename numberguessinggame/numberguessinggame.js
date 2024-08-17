//declaring page functionalities

const userinput = document.querySelector(".userinput");
const btnSubmit = document.querySelector(".submit");

const hint = document.querySelector(".hint");
const livesleft = document.querySelector(".livesleft");
const result = document.querySelector(".result");
const heart = document.querySelector(".heart");

console.log(userinput); // Should log the input element or null
console.log(btnSubmit); // Should log the button element or null
console.log(hint); // Should log the hint element or null
console.log(livesleft); // Should log the livesleft element or null
console.log(result);
console.log(heart);


let numberoflivesleft = 10;

let randomnumber = Math.floor(Math.random() * 100) + 1;

function checkGuess () {
    const userguess = Number(userinput.value);
    if (userguess === randomnumber) {
        result.textContent = "Congratulations! You guessed it correctly! 🥳";
        result.style.color = "rgb(0, 255, 149)";
        hint.textContent = "";
        setGameOver();
    }
    else if (numberoflivesleft === 0) {
        result.textContent = "Game Over! 😭";
        result.style.color = "Red";
        hint.textContent = "";
        setGameOver();
    }
    else {
        result.textContent = "Wrong! ❌";
        result.style.color = "red";
        result.style.fontWeight = "bold";

        numberoflivesleft--;

        livesleft.textContent = `${numberoflivesleft} ❤️ left!`;

        if (userguess < randomnumber) {
            hint.textContent = "Too Low!";
        }
        else if (userguess > randomnumber) {
            hint.textContent = "Too High!";
        }
    }
    userinput.value = "";
    userinput.focus();
}

btnSubmit.addEventListener("click", checkGuess);
console.log(randomnumber);

function setGameOver() {
    userinput.disabled = true;
    userinput.style.backgroundColor = "transparent"
    btnSubmit.disabled = true;
}
