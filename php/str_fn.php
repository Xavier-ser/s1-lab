<!DOCTYPE html>
<html>
<head>
    <title>PHP String Functions Example</title>
</head>
<body>

<h2>PHP String Function Demo</h2>

<form method="post">
    Enter a string: <input type="text" name="user_str" required>
    <br><br>

    <label>Select an operation:</label>
    <select name="operation">
        <option value=""><--Select--></option>
        <option value="strlen">String Length</option>
        <option value="strtoupper">Uppercase</option>
        <option value="strtolower">Lowercase</option>
        <option value="strrev">Reverse String</option>
        <option value="ucfirst">Capitalize First Letter</option>
        <option value="ucwords">Capitalize Each Word</option>
        <option value="trim">Trim Spaces</option>
    </select>

    <br><br>
    <input type="submit" name="submit" value="Apply">
</form>

<hr>

<?php
if (isset($_POST['submit'])) {
    $str = $_POST['user_str'];
    $op = $_POST['operation'];
    $result = "";

    switch ($op) {
        case "strlen":
            $result = "Length: " . strlen($str);
            break;
        case "strtoupper":
            $result = strtoupper($str);
            break;
        case "strtolower":
            $result = strtolower($str);
            break;
        case "strrev":
            $result = strrev($str);
            break;
        case "ucfirst":
            $result = ucfirst($str);
            break;
        case "ucwords":
            $result = ucwords($str);
            break;
        case "trim":
            $result = trim($str);
            break;
        default:
            $result = "Invalid operation!";
    }

    echo "<script>alert('Result: $result');</script>";
}
?>

</body>
</html>
