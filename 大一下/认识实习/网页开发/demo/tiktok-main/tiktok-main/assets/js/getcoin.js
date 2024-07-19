$(document).ready(function () {
  let selected = 0;

  $(".package").on("click", function(){
    selected = $(this).data("id",0)
    $(".package").removeClass("border-red-500")
    $(this).addClass("border-red-500")
  })



})