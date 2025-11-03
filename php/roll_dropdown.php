<!DOCTYPE html>
<html>
<head>
    <title>Roll Number Dropdown</title>
</head>
<body>

<form method="post">
    <label>Select Roll Number:</label>
    <select name="roll_no">
        <option value="">--Select--</option>
        <?php
        $conn = mysqli_connect("localhost", "root", "", "my_test_db");

        $result = mysqli_query($conn, "SELECT roll_no FROM student_reg");

        while ($row = mysqli_fetch_assoc($result)) {
        echo "<option value='" . $row['roll_no'] . "'>" . $row['roll_no'] . "</option>";

        }

        mysqli_close($conn);
        ?>
    </select>
    <input type="submit" value="Submit">
</form>

</body>
</html>
