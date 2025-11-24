<?php
$conn = new mysqli("localhost", "root", "", "my_test_db");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$roll = $_GET['roll'];

// Update record when form submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $address = $_POST['address'];
    $phone = $_POST['phone'];

    $conn->query("UPDATE student SET address='$address', ph_no='$phone' WHERE roll_no=$roll");

    header("Location: manage_students.php");
    exit;
}

// Fetch student data for the form
$result = $conn->query("SELECT * FROM student WHERE roll_no = $roll");
$student = $result->fetch_assoc();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Update Student</title>
</head>
<body>

<h2 style="text-align:center;">Update Student</h2>

<form method="POST" style="width: 300px; margin:auto;">

    <label>Roll No:</label><br>
    <input type="text" value="<?= $student['roll_no'] ?>" disabled><br><br>

    <label>Name:</label><br>
    <input type="text" value="<?= $student['name'] ?>" disabled><br><br>

    <label>Address:</label><br>
    <input type="text" name="address" value="<?= $student['address'] ?>"><br><br>

    <label>Phone:</label><br>
    <input type="text" name="phone" value="<?= $student['ph_no'] ?>"><br><br>

    <button type="submit">Update</button>

</form>

</body>
</html>
