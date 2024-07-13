$(document).ready(function () {
  const transactionData = `[
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    },
    {
      "amount":"30 coins",
      "method":{
        "img":"assets/images/icons/ic_mastercard.svg",
        "number":"*** *** *** 239"
      },
      "payment":"€ 0.35",
      "date":"11/28/2021 0:10 am",
      "orderId":"10000000017035254546354",
      "status":"completed"
    }
  ]`;

  $index = 0;
  $array = JSON.parse(transactionData);
  $html = "";
  $array.forEach((data, idx) => {
    if (idx < 10) {
      $html += '<tr><td class=" py-2 text-left">' + parseInt(Math.random() * 100) + 'coin' + '</td><td class=" py-2 text-center flex items-center justify-center"><img src="'
      $html += data.method.img + '" alt="card icon" /><span>' + data.method.number + '</span></td><td class=" py-2 text-center ">'
      $html += '€ ' + parseInt(Math.random() * 100) + '</td><td class=" py-2 text-center whitespace-nowrap">' + data.date + '</td><td class=" py-2 text-center ">'
      $html += parseInt(Math.random() * 100000000000000) + '</td><td class="text-right ">' + data.status + '</td></tr>'
    }
  });
  $(".transaction-table").html($html);
});