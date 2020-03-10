function strToJson(str){
	str = '["' + str + '"]';
	str = str.split(' ').join('');
	str = str.split(',').join('","');

	return JSON.parse(str);
}

function clickCalculate(){

	var theWord = $("#wordInput").val();

	var theList = $("#listInput").val();

	theList = strToJson(theList);

	var dataToSend = {"word": theWord, "letters": theList};

	$.get("/json", dataToSend, function(response){
		$("#ans").html(response["word"] + " : " + response["count"]);
	});

}
