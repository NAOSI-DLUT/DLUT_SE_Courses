function colorToggle() {
    const element = document.body;
    element.classList.toggle("dark-mode");

    if (window.matchMedia("(min-width: 1030px)").matches) {
      document.querySelectorAll('.auth-window').forEach((elem) => elem.classList.toggle("blue-mode"));
      document.querySelectorAll(".auth-window .change").forEach((elem) => elem.src = "./img/Twitter-logo-png.png");
    }
    else document.querySelectorAll('.auth-window').forEach((elem) => elem.classList.toggle("dark-mode"));

    document.querySelector(".fa-solid").classList.toggle("fa-moon");
    document.querySelector(".account").classList.toggle("black");
    document.querySelector(".heading1").classList.toggle("black");
    document.querySelector(".heading2").classList.toggle("black");
    document.querySelectorAll('.close i').forEach((elem) => elem.classList.toggle("black"));
    document.querySelector(".logo").classList.toggle("invert");

    document.querySelectorAll(".change").forEach(function (elem) {
      if (elem.src.match("./img/twitter-symbol.png")) elem.src = "./img/Twitter-logo-png.png";
      else elem.src = "./img/twitter-symbol.png";
    });

    document.querySelectorAll('.form h2').forEach((elem) => elem.classList.add('black'));
  }

  var flag = 0;
  document.querySelector('.toggle__button').addEventListener('click', function () {
    if (window.matchMedia("(min-width: 1030px)").matches) {
      document.querySelectorAll('.close i').forEach((elem) => elem.classList.toggle("black"));
      document.querySelectorAll('.form h2').forEach((elem) => elem.style.color = 'white');
      if (flag === 0) {
        document.querySelectorAll('.to-be-toggled').forEach((elem) => {
          elem.style.backgroundColor = 'black';
          elem.style.color = 'white';
          elem.style.border = '1px solid white';
        })
        document.querySelector('.user-input input').style.backgroundColor = 'white';
        document.querySelectorAll('.auth-window h3').forEach((elem) => elem.style.color = 'white');
        document.querySelectorAll('.auth-window h3 a').forEach((elem) => elem.style.color = 'black');
        flag = 1;
      }
      else {
        document.querySelectorAll('.to-be-toggled').forEach((elem) => {
          elem.style.backgroundColor = 'white';
          elem.style.color = 'black';
        })
        document.querySelectorAll('.auth-window h3').forEach((elem) => elem.style.color = '#72767b');
        document.querySelectorAll('.auth-window h3 a').forEach((elem) => elem.style.color = '#449eef');
        flag = 0;
      }
    }
    else {
      if (flag === 0) {
        document.querySelectorAll('.form h2').forEach((elem) => elem.style.color = 'black');
        flag = 1;
      }
      else {
        document.querySelectorAll('.form h2').forEach((elem) => elem.style.color = 'white');
        flag = 0;
      }
    }
  })

  let signin = document.querySelector('.signin');
  let signInWindow = document.querySelector('.signin-window');
  let body = document.querySelector('body');
  signin.addEventListener('click', function () {
    signInWindow.style.display = 'initial';
    body.style.overflow = 'hidden';
  });

  let signupBtn = document.querySelector('#signup-btn');
  let signIn = document.querySelector('.sign-in');
  let signUp = document.querySelector('.sign-up');
  signupBtn.addEventListener('click', function () {
    signUp.style.display = 'initial';
    signIn.style.display = 'none';
  })

  let logIn = document.querySelector('#log-in');
  logIn.addEventListener('click', function () {
    signIn.style.display = 'initial';
    signUp.style.display = 'none';
  })

  let close = document.querySelectorAll('.close');
  close.forEach(function (elem) {
    elem.addEventListener('click', function () {
      signInWindow.style.display = 'none';
      body.style.overflow = 'initial';
    });
  });