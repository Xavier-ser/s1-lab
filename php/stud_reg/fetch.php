<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.html");
    exit();
}

$conn = mysqli_connect("localhost","root","","my_test_db");
if (!$conn) {
    die("Database Error: " . mysqli_connect_error());
}

$username = $_SESSION['username'];

$result = mysqli_query($conn, "SELECT * FROM student WHERE username='$username'");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Details</title>
</head>
<body>

<h3>Student Details</h3>

<table border="1" cellpadding="8">
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Course</th>
        <th>Semester</th>
    </tr>

<?php
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td>".$row['roll_no']."</td>";
        echo "<td>".$row['name']."</td>";
        echo "<td>".$row['course']."</td>";
        echo "<td>".$row['semester']."</td>";
        echo "</tr>";
    }
} else {
    echo "<tr><td colspan='4'>No data found</td></tr>";
}
?>

</table>

<br>
<a href="logout.php">Logout</a>

</body>
</html>

<?php mysqli_close($conn); ?>
