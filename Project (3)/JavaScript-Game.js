var character = document.getElementById("character");
var blue = document.getElementById("Blue");
var pink = document.getElementById("Pink");
var counter = 0;
function jump() {
  //checking the condition if the class is not created yet, in order to avoid creating classes over and over again
  if (character.classList == "animate") {
    document.getElementById("jump").currentTime = 0;
    document.getElementById("jump").play();
    return;
  }
  character.classList.add("animate");
  //the character will only jump once because the class is set, in order to remove that, we will set a timeout
  setTimeout(function () {
    character.classList.remove("animate");
  }, 700);
}
//creating a function to check the values for the red and blue block and comparing them in order to determine if the game is over or not
var checkDead = setInterval(function () {
  let characterTop = parseInt(
    window.getComputedStyle(character).getPropertyValue("top")
  );
  let blueLeft = parseInt(
    window.getComputedStyle(blue).getPropertyValue("left")
  );
  //stopping the animation once the two blocks colliding
  if (blueLeft < 120 && blueLeft > 20 && characterTop >= 250) {
    blue.style.animation = "none";
    //seeting the math to calculate the scores
    alert("Game Over. score: " + Math.floor(counter / 100));
    counter = 0;
    blue.style.animation = "block 3s infinite linear";
  } else {
    counter++;
    //adding the scores if the blocks are not colliding
    document.getElementById("scoreSpan").innerHTML = Math.floor(counter / 100);
  }
}, 23);
