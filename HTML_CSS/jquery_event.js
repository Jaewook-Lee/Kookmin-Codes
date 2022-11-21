$("#target-id").click( function (event) {
    output = "User clicked on " + event.pageX + "/" + event.pageY;
    $("#display").text(output);
} )