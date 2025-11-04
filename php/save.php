<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_test_db";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$name = $_POST['name'];
$gender = $_POST['gender'];
$mark1 = $_POST['mark1'];
$mark2 = $_POST['mark2'];
$roll = $_POST['roll'];
$total = $mark1 + $mark2;

$check_sql = "SELECT * FROM student_reg WHERE roll_no = '$roll'";
$result = mysqli_query($conn, $check_sql);

if (mysqli_num_rows($result) > 0) {
    echo "<script>
            alert('Error: Roll number already exists! Please enter a unique roll number.');
            window.location.href = 'stud_reg.html';
          </script>";
} else {
    $sql = "INSERT INTO student_reg (name, gender, mark1, mark2, roll_no, total)
            VALUES ('$name', '$gender', '$mark1', '$mark2', '$roll', '$total')";

    if (mysqli_query($conn, $sql)) {
        echo "<script>
                alert('Data saved successfully!');
                window.location.href = 'stud_reg.html';
              </script>";
    } else {
        $error = addslashes(mysqli_error($conn));
        echo "<script>
                alert('Database Error: $error');
                window.location.href = 'stud_reg.html';
              </script>";
    }
}

mysqli_close($conn);
?>
