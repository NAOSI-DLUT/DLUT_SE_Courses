var loadingMsgIndex,
    botui = new BotUI('Chat-bot'),
    API = 'https://api.ownthink.com/bot?appid=7aa791d834f9f38305a05bfdf7ea9d79&userid=user&spoken=';

function sendXHR(Qu, cb) {
  var xhr = new XMLHttpRequest();
  var self = this;
  xhr.open('GET', API + Qu );
  xhr.onload = function () {
    var res = JSON.parse(xhr.responseText)
    cb(res.data.info.text);
  }
  xhr.send();
}

function init() {
  botui.message
  .bot({
    delay: 1000,
    content: " 请问您有什么问题？"
  })
  .then(function () {
    return botui.action.text({
      delay: 1000,
      action: {
        value: '邮局的开放时间',
        placeholder: '请输入您的问题'
      }
    })
  }).then(function (res) {
    loadingMsgIndex = botui.message.bot({
      delay: 200,
      loading: true
    }).then(function (index) {
      loadingMsgIndex = index;
      sendXHR(res.value, showTexts)
    });
  });
}

function showTexts(Texts) {
  botui.message
  .update(loadingMsgIndex, {
    content: Texts
  })
  .then(init); // ask again for questions. Keep in loop.
}

botui.message
  .bot({
    delay: 1000,
    content: "Hi, there👋"
  });
  
init();

//打开/关闭聊天框
$(".chatBtn").click(function () {
  $(".chatBox").toggle(300);
})
$(".chat-close").click(function () {
  $(".chatBox").toggle(300);
})