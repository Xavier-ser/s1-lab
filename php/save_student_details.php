<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_test_db";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$roll = $_POST['roll'];
$name = $_POST['name'];
$address = $_POST['address'];
$ph = $_POST['ph'];
$username = $_POST['username'];
$password = $_POST['password'];
$confirm = $_POST['con_pass'];

$check_sql = "SELECT * FROM stud_registration WHERE `Roll No` = '$roll'";
$result = mysqli_query($conn, $check_sql);

if (mysqli_num_rows($result) > 0) {
    echo "<script>
            alert('Error: Roll number already exists! Please enter a unique roll number.');
            window.location.href = 'stud_reg.html';
          </script>";   
} else {
    $sql = "INSERT INTO stud_registration (`Roll No`, `Name`, `Address`, `Ph No`, `Username`, `Password`, `Confirm Password`)
            VALUES ('$roll', '$name', '$address', '$ph', '$username', '$password', '$confirm')";
    
    if (mysqli_query($conn, $sql)) {
        echo "<script>
                alert('Data saved successfully!');
                window.location.href = 'student_registration.html';
              </script>";
    } else {
        echo "<script>
                alert('Database Error: " . addslashes(mysqli_error($conn)) . "');
                window.location.href = 'student_registration.html';
              </script>";
    }
}

mysqli_close($conn);
