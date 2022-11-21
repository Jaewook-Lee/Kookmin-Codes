module.exports = {    // 크롤링한 결과를 다른 파일로 옮기기 위해 이 js 파일을 하나의 module로 만듭니다.
	getResult: function() {    // getResult는 이 js 함수의 이름입니다.
		const fs = require('fs');

		const data = fs.readFileSync('./schedule.html', 'utf-8');

		const openDate = "<span class='date'>";    // 갖고 싶은 내용(날짜)만을 뽑아내기 위한 자르기 시작점
		const closeSpan = "</span>";               // 갖고 싶은 내용만을 뽑아내기 위한 자르기 끝점, 날짜와 행사 내용의 끝점이 동일합니다.
		const openValue = "<span class='fr'>";     // 갖고 싶은 내용(행사 내용)만을 뽑아내기 위한 자르기 시작점

		let nextStartIndex = 0;
		const results = [];    // 뽑아낸 내용들을 저장하기 위한 object을 하나 선언합니다.
		while (true) {
			const dateIndex = data.indexOf(openDate, nextStartIndex);    // 날짜의 시작점의 인덱스를 찾습니다.
			if (dateIndex === -1) {    // 찾아내지 못했다면 while문을 벗어납니다.
				break;
			}
			const dateEndIndex = data.indexOf(closeSpan, dateIndex);    // 날짜의 끝점의 인덱스를 찾습니다.

			const dateValue = data.substring(dateIndex + openDate.length, dateEndIndex).match(/\d+/g).map(Number);    // 날짜에서 숫자만을 뽑습니다.
        		nextStartIndex = dateIndex + 1;

        		const valueIndex = data.indexOf(openValue, nextStartIndex);    // 행사 내용의 시작점의 인덱스를 찾습니다.
        		if (valueIndex === -1) {    // 찾아내지 못했다면 while문을 벗어납니다.
            			break;
        		}
        		const valueEndIndex = data.indexOf(closeSpan, valueIndex);    // 행사 내용의 끝점의 인덱스를 찾습니다.

        		let value = data.substring(valueIndex + openValue.length, valueEndIndex);
        		value = value.replace(/(\r\n\t\t)/g, '');
        		value = value.replace(/(<br>\t\t|<br>|\t\t)/g, '');    // 행사 내용을 뽑아온 후 \r, \t, \n, <br>을 지웁니다.

			results[dateValue] = value;    // 날짜 : 행사 내용 = key : value 관계를 맺도록 설정합니다.
        		nextStartIndex = valueIndex + 1;
		}
		return results;
	}
}
//console.log(results);    // 크롤링 확인용 문장입니다. 터미널에서 크롤링을 한 결과가 출력됩니다.
