const myModule = require('./data_crawling');    // data_crawling 모듈을 myModule 이름으로 부릅니다.
let crawlData = myModule.getResult();    // myModule 안에 있는 getResult 함수를 val 변수에 저장했습니다.
console.log(crawlData);
/*
const keys = Object.keys(crawlData);
const events = Object.values(crawlData);
console.log(keys);
console.log(events);
*/
