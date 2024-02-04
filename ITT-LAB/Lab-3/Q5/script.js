function calculateAndDisplay() {
    var tableBody = document.createElement("tbody");

    for (var i = 0; i <= 10; i++) {
        var square = i * i;
        var cube = i * i * i;

        var row = tableBody.insertRow();
        var cell1 = row.insertCell(0);
        var cell2 = row.insertCell(1);
        var cell3 = row.insertCell(2);

        cell1.textContent = i;
        cell2.textContent = square;
        cell3.textContent = cube;
    }

    var table = document.querySelector("table");
    table.appendChild(tableBody);
}

calculateAndDisplay();