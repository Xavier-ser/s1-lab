<!DOCTYPE html>
<html>
<head>
    <title>Welcome Page</title>
</head>
<body>

<?php
if (isset($_POST['username'])) {
    $name = $_POST['username']; 
    if($name != ""){
    echo "<h2>Melcow, $name!</h2>";
    } else {
    echo "<h2>No name provided!</h2>";
}
} 
?>

</body>
</html>
