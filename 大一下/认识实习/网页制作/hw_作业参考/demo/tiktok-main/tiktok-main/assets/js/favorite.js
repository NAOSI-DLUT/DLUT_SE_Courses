$(document).ready(function () {

  const categoryData = `[
    {
      "title":"Home",
      "icon":"assets/images/home.svg",
      "link":"index.html"
    },
    {
      "title":"Explore",
      "icon":"assets/images/explore.svg",
      "link":"explorer.html"
    },
    {
      "title":"Followers",
      "icon":"assets/images/following.svg",
      "link":"followers.html"
    },
    {
      "title":"Following",
      "icon":"assets/images/following.svg",
      "link":"following.html"
    },
    {
      "title":"Friends",
      "icon":"assets/images/friends.svg",
      "link":"friends.html"
    },
    {
      "title":"Favorite",
      "icon":"assets/images/favorite_active.svg",
      "link":"favorite.html"
    }
  ]`;
 
  const users = `[
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
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png"
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
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png"
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
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png"
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
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png"
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
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png"
    }
  ]`


  $index = 0;
  $array = JSON.parse(categoryData);
  $html = "";
  $array.forEach((data, idx) => {
    $html +=
      '<div ><a href="' +
      data.link +
      '" class="flex gap-3 items-center cursor-pointer"><img src="';
    $html += data.icon + '" class="w-6" alt="side icon"/>';
    $html += '<span class="text-lg hover:text-red-500 text-black font-bold">';
    $html += data.title + "</span></a></div>";
  });
  $(".category-list").html($html);


  $array = JSON.parse(users);
  $html = "";
  $array.forEach((data,idx)=>{
    $html += '<div class="flex items-center justify-between gap-1"><div class="flex gap-4 items-center cursor-pointer"><img src="'
    $html += data.image + '" alt="avatar" class="w-10 h-10"><div class="flex flex-col w-full"><span class="text-black text-md font-bold">'
    $html += data.name + '</span><div class="flex gap-4 items-center"><span class="text-black text-sm">'
    $html += data.location + '</span><img src="' + data.flag + '" alt="flag" class="rounded-sm"></div></div></div><div class="flex gap-1 sm:gap-4 text-white text-xs sm:text-sm">'
    if(idx%(parseInt(Math.random()*10%5)) == 0){
      $html += '<button class="fav-button" data-like="true"><img src="assets/images/icons/ic_star.svg" alt="fav icon"/></button>'
    }
    else{
      $html += '<button class="fav-button" data-like="false"><img src="assets/images/icons/ic_star_solid.svg" alt="fav icon"/></button>'
    }
    $html += '</div></div>'
  })

  $(".list-container").html($html);

  $(".fav-button").on("click", function(){
    if($(this).data('like')){
      $(this).html('<img src="assets/images/icons/ic_star_solid.svg" alt="fav icon"/>')
      $(this).data('like', false)
    }
    else{
      $(this).html('<img src="assets/images/icons/ic_star.svg" alt="fav icon"/>')
      $(this).data('like', true)
    }
  })

});
