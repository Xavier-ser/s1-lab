<?php
$servername = "localhost";
$username = "root";      
$password = "";          
$dbname = "my_test_db";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$name = $_POST['name'];
$email = $_POST['email'];
$marks = $_POST['marks'];




















$sql = "INSERT INTO student (name, email, marks) VALUES ('$name', '$email','$marks')";

if ($conn->query($sql) === TRUE) {
    echo "Data saved successfully!";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
