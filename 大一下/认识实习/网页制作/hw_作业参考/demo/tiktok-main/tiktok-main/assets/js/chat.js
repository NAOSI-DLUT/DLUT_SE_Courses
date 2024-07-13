$(document).ready(function () {
  const userData = `[
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"recording",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"img",
      "status":"recording",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png",
      "msg":"Bro nice to meet you",
      "msgtype":"img",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png",
      "msg":"Bro nice to meet you",
      "msgtype":"img",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"recording",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"Willsmith",
      "image":"assets/images/man1.png",
      "location":"Willsmith",
      "flag":"assets/images/flag_ca.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"edshreean",
      "image":"assets/images/man2.png",
      "location":"Ed Sheeran",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"typing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"billieeilish",
      "image":"assets/images/man3.png",
      "location":"Billie Eilish",
      "flag":"assets/images/flag_eu.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"manuelneuer",
      "image":"assets/images/man4.png",
      "location":"Manuel Neuer",
      "flag":"assets/images/flag_us.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    },
    {
      "name":"toni.kr8s",
      "image":"assets/images/man5.png",
      "location":"Toni Kroos",
      "flag":"assets/images/flag_uk.png",
      "msg":"Bro nice to meet you",
      "msgtype":"text",
      "status":"nothing",
      "date":"11/16/19",
      "read":"true"
    }
  ]`

  const chatData = `[
    {
      "msg":"I missed up tonight",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"I just lost another fight",
      "sender":"you",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"OK, it seems paskal is not hiding here",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"file|png",
      "name":"park.doc",
      "size":"2.8M"
    },
    {
      "msg":"captuer",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"Aaaahk OMG!",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"How about 23 out of 46?",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    },
    {
      "msg":"OK paskal it is not so bad staying here.",
      "sender":"me",
      "read":"true",
      "time":"11:40",
      "type":"chat"
    }
  ]`

  $index = 0;
  $array = JSON.parse(userData);
  $html = "";
  $array.forEach((data, idx) => {
    $html += '<div class="flex relative justify-beetween chat-user px-4 py-2 bg-white w-full gap-4 cursor-pointer" data-index=' + idx + '><img src="'
    $html += data.image + '" alt="user" class="w-10 h-10"/><div class="flex flex-col w-full"><div class="break-all flex items-center justify-between text-sm "><span class="truncate w-1/2 font-bold">'
    $html += data.name + '</span><span class="flex-shrink-0 text-xs text-gray-500">' + data.date + '</span></div><div class="flex items-center">'

    if (data.msgtype == "img") {
      $html += '<img src="assets/images/icons/ic_photo.svg" alt="read"/><p class="truncate text-xs text-gray-500">&nbsp;Photo</p>'
    }
    else if (data.status == "recording") {
      $html += '<img src="assets/images/icons/ic_recording.svg" alt="read"/><p class="truncate text-xs text-gray-500">&nbsp;0:14</p>'
    }
    else if (data.status == "typing") {
      $html += '<p class="text-xs text-gray-500">Typing......</p>'
    }
    else if (data.read == "true") {
      $html += '<img src="assets/images/icons/ic_read.svg" alt="read"/><p class="truncate text-xs text-gray-500">&nbsp; ' + data.msg + '</p>'
    }
    $html += `</div></div>
      <div class="flex absolute right-0 transform translate-x-full h-full top-0">
        <div class="cursor-pointer btn-more w-16 flex items-center justify-center flex-col bg-gray-400 text-white text-sm p-1 relative"  data-index=` + idx + `>
          <div class="submenu-`+idx+` absolute right-0 bottom-0 transform translate-y-full hidden ">
            <ul class="divide-y border bg-white w-48 mt-2 font-semibold text-gray-600 rounded-md">
              <li class="cursor-pointer px-6 py-2">Mute</li>
              <li class="cursor-pointer px-6 py-2">Contact Info</li>
              <li class="cursor-pointer px-6 py-2">Clear Chat</li>
              <li class="cursor-pointer px-6 py-2 text-red-500">Delete Chat</li>
            </ul>
          </div>
        <img src="assets/images/icons/ic_more_white.svg" alt="more" />
        <p>More</p>
        </div>
        <div class="btn-archive w-16 flex items-center justify-center flex-col bg-red-500 text-white text-sm p-1">
        <img src="assets/images/icons/ic_inbox.svg" alt="inbox" />
        <p>Archive</p>
        </div>
      </div>
      </div>
    `
  });
  $(".chat-users").html($html);


  $array = JSON.parse(chatData);
  $html = "";
  $array.forEach((data, idx) => {
    if (data.type.split("|")[0] != "file") {
      if (data.sender == "me") {
        $html += `<div class="bg-gray-300 p-2 flex flex-col max-w-3/4 max-w-md ml-auto rounded-md"><p>`
      }
      else {
        $html += `<div class="bg-blue-100 p-2 flex flex-col max-w-3/4 max-w-md mr-auto rounded-md relative">
          <div class="emoji transform translate-x-5 absolute right-0 top-1 cursor-pointer" data-index="`+ idx + `">
            <img src="assets/images/icons/ic_emoticon.svg" alt="emoji"/>
          </div>
          <div id="emoji-`+ idx + `" class="p-1 absolute bottom-0 left-3 transform translate-y-1/2 bg-white border items-center rounded-full hidden">
            <p>😍</p>
          </div>
          <div id="dialog-`+ idx + `" class="dialog bg-black p-4 rounded-md absolute right-0 top-0 transform translate-x-1/2 -mr-3 -translate-y-16 flex gap-2 hidden">
            <img src="assets/images/icons/ic_prev_emoji.svg" alt="select" />
            <div class="flex gap-4 relative">
              <p class="cursor-pointer emoticon" data-index="`+ idx + `">😍</p>
              <p class="cursor-pointer emoticon" data-index="`+ idx + `">😡</p>
              <p class="cursor-pointer emoticon" data-index="`+ idx + `">🥱</p>
              <p class="cursor-pointer emoticon" data-index="`+ idx + `">😫</p>
              <div class="bg-black w-4 h-4 absolute transform left-1/2 -translate-x-1/2 translate-y-5 rotate-45 bottom-0"></div>
            </div>
            <img src="assets/images/icons/ic_next_emoji.svg" alt="select" />
          </div>
        <p>`
      }

      $html += data.msg + '</p><div class="flex ml-auto gap-2"><span class="text-xs">'
      $html += data.time + '</span>'
      if (data.read == "true") {
        $html += '<img src="assets/images/icons/ic_read.svg" alt="read" />'
      }
      $html += '</div></div>'
    }
    else {
      $html += `<div class="bg-gray-300 p-2 flex flex-col w-max max-w-md ml-auto rounded-md">
        <div class="flex justify-between p-2 rounded-md gap-4" style="background-color:#7676803d">
          <div class="flex gap-2 w-full items-center">
            <img src="assets/images/icons/ic_file.svg" alt="file" />
            <p class="whitespace-nowrap">FILE NAME</p>
          </div>
          <a href="#" class="cursor-pointer">
            <img src="assets/images/icons/ic_download.svg" alt="download" class />
          </a>
        </div>
        <div class="flex justify-between mt-1">
        <div class="flex gap-2 text-xs">
        <p>2.8M</p>
        <p>PNG</p>
        </div>
          <div class="flex ml-auto gap-2">
            <span class="text-xs">12:67 Pm</span>
            <img src="assets/images/icons/ic_read.svg" alt="read" />
          </div>        
        </div>
      </div>`
    }
  });
  $(".chat-box").html($html);

  let menuopen = false

  $(".chat-menu").on("click", function () {
    menuopen = !menuopen
    if (menuopen) {
      $(".expand-menu").removeClass("hidden")
    }
    else {
      $(".expand-menu").addClass("hidden")
    }
  })

  $(".btn-attach").on("click", function () {
    menuopen = !menuopen
    if (menuopen) {
      $(".menu-attach").removeClass("hidden")
    }
    else {
      $(".menu-attach").addClass("hidden")
    }
  })

  $(".chat-user").on("click", function () {
    var index = $(this).data("index")
    var subid = ".submenu-"+index
    console.log()
    $(".selected-user-name").html(JSON.parse(userData)[index].name)
    $(".selected-user-image").attr("src", JSON.parse(userData)[index].image)
    if (((window.innerWidth > 0) ? window.innerWidth : screen.width) < 640) {
      // $(".chat-mobile").addClass("hidden")
      // $(".chat-view").removeClass("hidden")
      if($(this).hasClass("transform")){
        $(this).removeClass("transform z-10")
        $(".mask").addClass("hidden")
      }
      else{
        $(this).addClass("transform -translate-x-32 duration-200 z-10")
      }
      
    }
  })

  $(".emoticon").on('click', function () {
    $(".dialog").removeClass("hidden")
    $(".dialog").addClass("hidden")
    var emojiId = "#emoji-" + $(this).data("index")
    $(emojiId).removeClass("hidden")
    $(emojiId).html($(this).html())
  })

  $(".emoji").on('click', function () {
    var id = "#dialog-" + $(this).data("index")

    console.log(id)
    $(id).removeClass("hidden")

  })

  $(".btn-cancel").on("click", function () {
    $(".menu-attach").removeClass("hidden")
    $(".menu-attach").addClass("hidden")
  })

  $(".btn-contact").on("click", function () {
    console.log("kkk", (window.innerWidth > 0) ? window.innerWidth : screen.width)
    if (((window.innerWidth > 0) ? window.innerWidth : screen.width) < 640) {
      $(".chat-mobile").removeClass("hidden")
      $(".chat-view").addClass("hidden")
    }
  })


  $(".btn-more").on("click", function(event){
    $(".mask").removeClass("hidden")
    var index = $(this).data("index")
    var subid = ".submenu-"+index
    // $(subid).removeClass("hidden")
    event.stopPropagation();
    if( !$(subid).hasClass("hidden")){
      $(subid).addClass("hidden")
    }
    else{
      $(subid).removeClass("hidden")
    }
    // $(this).preventDefault();
    
  })

  $(".btn-archive").on("click", function(){
    if (((window.innerWidth > 0) ? window.innerWidth : screen.width) < 640) {
      $(".chat-user").removeClass("transform")
      $(".chat-mobile").addClass("hidden")
      $(".chat-view").removeClass("hidden")
      $(".mask").addClass("hidden")
    }
  })

});
