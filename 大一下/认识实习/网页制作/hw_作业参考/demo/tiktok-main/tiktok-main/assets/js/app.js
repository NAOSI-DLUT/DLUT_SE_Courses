$(document).ready(function () {
  const people = `[
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man3.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_uk.png"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man4.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man3.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_uk.png"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man4.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_us.png"
    }
  ]`;


  let mobileMenu = false;
  $index = 0;
  $array = JSON.parse(people);
  $html = "";
  $array.forEach((data) => {
    $html += '<div class="flex gap-4 items-center cursor-pointer"><a href="profile.html" class="w-12 h-12 flex items-center"><img src="';
    $html += data.image + '" alt="avatar" /></a>';
    $html +=
      '<div class="flex flex-col w-full"><span class="text-black text-xl">';
    $html +=
      data.name +
      '</span><div class="flex gap-4 items-center"><span class="text-black text-sm">';
    $html += data.location + '</span><img src="';
    $html += data.flag;
    $html += '" alt="flag" class="rounded-sm"/></div></div></div>';
  });
  $("#user-list").html($html);

  $(".menu-button").on("click", function(){
    mobileMenu = !mobileMenu;
    $("#menu-icon").attr("src",!mobileMenu?"assets/images/menu.svg":"assets/images/close.svg")
    toggleMobileMenu()
  })
  
  function toggleMobileMenu(){
    mobileMenu?$("#menu-mobile").css("display","flex"):$("#menu-mobile").hide()
  }
  function updateImage(){
    $("#frame").attr("src",imageList[$index]);
  }

  let menuopen = false

  $(".btn-menu").on("click", function(){
    menuopen = !menuopen
    if(menuopen){
      $(".toggle-menu").removeClass("hidden")
      $(".icon-menu").attr("src","assets/images/icons/angle_up.svg")
    }
    else{
      $(".toggle-menu").addClass("hidden")
      $(".icon-menu").attr("src","assets/images/icons/angle_down.svg")
    }
  })
});
