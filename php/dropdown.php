<!DOCTYPE html>
<html>
<head>
    <title>Number Dropdown Example</title>
</head>
<body>

<form method="post">
    <label>Select a number:</label>
    <select name="number">
        <?php
        for ($i = 1; $i <= 100; $i++) {
            echo "<option value='$i'>$i</option>";
        }
        ?>
    </select>
    <input type="submit" name="submit" value="Submit">
</form>

<?php
if (isset($_POST['submit'])) {
    $num = $_POST['number'];
    echo "<script>alert('You selected: $num');</script>";
}
?>

</body>
</html>
