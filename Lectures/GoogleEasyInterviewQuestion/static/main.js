function clickJSON(){
            
	var xhttp = new XMLHttpRequest();

	xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
		   // Typical action to be performed when the document is ready:
		   // alert(xhttp.responseText);
		   var ansSpace = document.getElementById("ans");

		   var data = JSON.parse(xhttp.responseText);
		   
		   ansSpace.innerHTML = "Word: " + data["word"] + " appears " + data["count"] + " times.";
		}
	};
	var string = "/json"
	xhttp.open("GET", string, true);
	xhttp.send();
}
