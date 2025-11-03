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
$gender = $_POST['gender'];
$mark1 = $_POST['mark1'];
$mark2 = $_POST['mark2'];
$roll = $_POST['roll'];
$total = $mark1 + $mark2;

$check_sql = "SELECT * FROM student_reg WHERE roll_no = '$roll'";
$result = $conn->query($check_sql);

if ($result->num_rows > 0) {
    echo "<script>
            alert('Error: Roll number already exists! Please enter a unique roll number.');
            window.location.href = 'stud_reg.html';
          </script>";
} else {
    $sql = "INSERT INTO student_reg (name, gender, mark1, mark2, roll_no, total)
            VALUES ('$name', '$gender', '$mark1', '$mark2', '$roll', '$total')";

    if ($conn->query($sql) === TRUE) {
        echo "<script>
                alert('Data saved successfully!');
                window.location.href = 'stud_reg.html';
              </script>";
    } else {
        echo "<script>
                alert('Database Error: " . addslashes($conn->error) . "');
                window.location.href = 'stud_reg.html';
              </script>";
    }
}

$conn->close();
?>
