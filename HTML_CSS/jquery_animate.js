$(document).ready(function () {
    $("#animate").click(function () {
        $("#animation-demo").animate({backgroundColor: "#aa0000", left: "170px", opacity: "0.5"}, 2000);
        $("#animation-demo").animate({fontSize: "5rem"}, 1000);
    });
});