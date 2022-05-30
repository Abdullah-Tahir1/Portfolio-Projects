$(document).ready(function () {
  //variables
  $surface = $(".surface");
  $car = $(".car");
  $img = $(".car img");
  let flag = true;
  const cars = ["Images/Bus-On.png", "Images/Bus-Off.png"];
  //keypress events
  $(document).on("keypress", function (e) {
    if (e.which == 13) {
      $($surface).toggleClass("moveRight");
      $($car).toggleClass("suspension");
    }
  });
  //light
  $(document).on("keypress", function (e) {
    if (e.which == 32) {
      if (flag) {
        flag = false;
        $img.attr("src", cars[0]);
      } else {
        flag = true;
        $img.attr("src", cars[1]);
      }
    }
  });
});
