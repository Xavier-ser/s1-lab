<?php
session_start();
$conn = mysqli_connect("localhost", "root", "", "my_test_db");

if (!$conn) {
    die("Database connection failed: " . mysqli_connect_error());
}

if (!isset($_SESSION['username'])) {
    header("Location: login.html");
    exit();
}

$username = $_SESSION['username'];

$sql = "SELECT student.roll_no, student.name, student.address, student.phone,
               marks.subject1, marks.subject2, marks.subject3
        FROM student
        JOIN marks ON student.roll_no = marks.roll_no
        WHERE student.username = '$username'";

$result = mysqli_query($conn, $sql);

if ($row = mysqli_fetch_assoc($result)) {
    echo "<h2>Welcome, " . htmlspecialchars($row['name']) . "!</h2>";
    echo "<p><b>Roll No:</b> " . $row['roll_no'] . "</p>";

    echo "<h3>Your Marks:</h3>";
    echo "<table border='1' cellpadding='8'>
            <tr><th>Subject 1</th><th>Subject 2</th><th>Subject 3</th></tr>
            <tr><td>{$row['subject1']}</td><td>{$row['subject2']}</td><td>{$row['subject3']}</td></tr>
          </table>";
} else {
    echo "<p>No marks found yet. Please contact admin.</p>";
}

mysqli_close($conn);
?>
