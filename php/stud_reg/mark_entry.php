<!DOCTYPE html>
<html>
<head>
    <title>Marks Entry</title>
</head>
<body>

<?php
$conn = mysqli_connect("localhost","root","","my_test_db");
if(!$conn){
    die("Connection Failed: " . mysqli_connect_error());
}

$roll = "";
$name = "";

/* When roll number is selected */
if(isset($_POST['show'])){
    $roll = $_POST['roll_no'];

    // fetch name from student table
    $q = mysqli_query($conn, "SELECT name FROM student WHERE roll_no='$roll'");
    if($row = mysqli_fetch_assoc($q)){
        $name = $row['name'];
    }

    // fetch marks if already exists
    $m = mysqli_query($conn, "SELECT * FROM marks WHERE roll_no='$roll'");
    if($mr = mysqli_fetch_assoc($m)){
        $science = $mr['science'];
        $maths = $mr['maths'];
        $english = $mr['english'];
    } else {
        // if no marks present, show empty fields
        $science = "";
        $maths = "";
        $english = "";
    }
}


/* When marks are submitted */
if(isset($_POST['save'])){
    $roll = $_POST['roll_no'];
    $science = $_POST['mark1'];
    $maths = $_POST['mark2'];
    $english = $_POST['mark3'];
    $total = $science + $maths + $english;

    // check if record already exists
    $check = mysqli_query($conn, "SELECT * FROM marks WHERE roll_no='$roll'");

    if(mysqli_num_rows($check) > 0){
        // update existing record
        mysqli_query($conn, "UPDATE marks 
                             SET science='$science', maths='$maths', english='$english', total='$total'
                             WHERE roll_no='$roll'");
        echo "<p style='color:blue;font-weight:bold;'>Marks Updated Successfully!</p>";
    } else {
        // insert new record
        mysqli_query($conn, "INSERT INTO marks(roll_no, science, maths, english, total)
                             VALUES('$roll', '$science', '$maths', '$english', '$total')");
        echo "<p style='color:green;font-weight:bold;'>Marks Saved Successfully!</p>";
    }
}

?>

<br><br>
<form method="post">
    <label>Select Roll Number:</label>
    <select name="roll_no" required>
        <option value="">--Select--</option>
        <?php
        $res = mysqli_query($conn, "SELECT roll_no FROM student");
        while($r = mysqli_fetch_assoc($res)){
            $sel = ($r['roll_no'] == $roll) ? "selected" : "";
            echo "<option value='".$r['roll_no']."'>".$r['roll_no']."</option>";
        }
        ?>
    </select>
    <input type="submit" name="show" value="Show Details">
</form>

<?php if($roll && $name): ?>
<hr>
<h3>Student Details</h3>
<form method="post">
    <input type="hidden" name="roll_no" value="<?php echo $roll; ?>">
    <p>Name: <b><?php echo $name; ?></b></p>
    <p>Science: <input type="number" name="mark1" value="<?php echo $science; ?>" required></p>
    <p>Maths: <input type="number" name="mark2" value="<?php echo $maths; ?>" required></p>
    <p>English: <input type="number" name="mark3" value="<?php echo $english; ?>" required></p>

    <input type="submit" name="save" value="Submit">
    <input type="reset" name="reset" value="Reset">
</form>
<?php endif; ?>

<?php mysqli_close($conn); ?>

</body>
</html>
