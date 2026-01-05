<!DOCTYPE html>
<html>
<head>
    <title>Search Student</title>
</head>
<body>

<?php
$conn = mysqli_connect("localhost","root","","my_test_db");
if(!$conn){
    die("Connection Failed: " . mysqli_connect_error());
}

$roll = "";
$name = "";
$course = "";
$semester = "";
$msg = "";

if(isset($_POST['search'])){
    $roll = $_POST['roll_no'];

    $q = mysqli_query($conn, "SELECT * FROM student WHERE roll_no='$roll'");

    if(mysqli_num_rows($q) > 0){
        $row = mysqli_fetch_assoc($q);
        $name = $row['name'];
        $course = $row['course'];
        $semester = $row['semester'];
    } else {
        $msg = "Student not found!";
    }
}
?>

<h2>Search Student</h2>

<form method="post">
    <label>Enter Roll Number:</label>
    <input type="text" name="roll_no" required>
    <input type="submit" name="search" value="Search">
</form>

<?php if($name): ?>
<hr>
<h3>Student Details</h3>
<p>Roll No: <b><?php echo $roll; ?></b></p>
<p>Name: <b><?php echo $name; ?></b></p>
<p>Course: <b><?php echo $course; ?></b></p>
<p>Semester: <b><?php echo $semester; ?></b></p>
<?php endif; ?>

<?php if($msg): ?>
<p style="color:red;font-weight:bold;"><?php echo $msg; ?></p>
<?php endif; ?>

<?php mysqli_close($conn); ?>

</body>
</html>
