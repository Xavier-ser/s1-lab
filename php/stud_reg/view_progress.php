<?php
$conn = new mysqli("localhost", "root", "", "my_test_db");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch roll numbers for dropdown from marks table
$rollResult = $conn->query("SELECT roll_no FROM marks");

// Fetch top student if requested
$topStudent = null;
if (isset($_GET['view']) && $_GET['view'] == 'top') {
    $result = $conn->query("
        SELECT m.roll_no, s.name, m.science, m.maths, m.english, 
               (m.science + m.maths + m.english) AS total_mark
        FROM marks m
        JOIN student s ON m.roll_no = s.roll_no
        ORDER BY total_mark DESC
        LIMIT 1
    ");
    $topStudent = $result->fetch_assoc();
}

// Fetch searched student if form submitted
$searchedStudent = null;
if (isset($_POST['search'])) {
    $roll_no = $_POST['roll_no'];
    $result = $conn->query("
        SELECT m.roll_no, s.name, m.science, m.maths, m.english, 
               (m.science + m.maths + m.english) AS total_mark
        FROM marks m
        JOIN student s ON m.roll_no = s.roll_no
        WHERE m.roll_no = $roll_no
    ");
    $searchedStudent = $result->fetch_assoc();
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>View Progress Card</title>
    <style>
        body { font-family: Arial, sans-serif; }
        .container { width: 80%; margin: auto; }
        h2 { text-align: center; }
        table { border-collapse: collapse; width: 60%; margin: 20px auto; }
        th, td { border: 1px solid #000; padding: 8px; text-align: center; }
        select, button { padding: 5px 10px; margin-right: 5px; }
        a { text-decoration: none; color: blue; margin-left: 20px; }
    </style>
</head>
<body>
<div class="container">

<h2>View Progress Card</h2>

<!-- Link to view top student -->
<a href="view_progress.php?view=top">View Top Student</a>

<!-- Top student display -->
<?php if($topStudent): ?>
    <h3 style="text-align:center;">Top Student</h3>
    <table>
        <tr>
            <th>Roll No</th>
            <th>Name</th>
            <th>Science</th>
            <th>Maths</th>
            <th>English</th>
            <th>Total</th>
        </tr>
        <tr>
            <td><?= $topStudent['roll_no'] ?></td>
            <td><?= $topStudent['name'] ?></td>
            <td><?= $topStudent['science'] ?></td>
            <td><?= $topStudent['maths'] ?></td>
            <td><?= $topStudent['english'] ?></td>
            <td><?= $topStudent['total_mark'] ?></td>
        </tr>
    </table>
<?php endif; ?>

<hr>

<!-- Search by roll number -->
<h3 style="text-align:center;">Search Student</h3>
<form method="POST" style="text-align:center; margin-bottom: 20px;">
    <select name="roll_no" required>
        <option value="">Select Roll No</option>
        <?php 
        // Reset pointer to first row
        $rollResult->data_seek(0);
        while($row = $rollResult->fetch_assoc()): ?>
            <option value="<?= $row['roll_no'] ?>"><?= $row['roll_no'] ?></option>
        <?php endwhile; ?>
    </select>
    <button type="submit" name="search">Search</button>
</form>

<!-- Display searched student -->
<?php if($searchedStudent): ?>
    <table>
        <tr>
            <th>Roll No</th>
            <th>Name</th>
            <th>Science</th>
            <th>Maths</th>
            <th>English</th>
            <th>Total</th>
        </tr>
        <tr>
            <td><?= $searchedStudent['roll_no'] ?></td>
            <td><?= $searchedStudent['name'] ?></td>
            <td><?= $searchedStudent['science'] ?></td>
            <td><?= $searchedStudent['maths'] ?></td>
            <td><?= $searchedStudent['english'] ?></td>
            <td><?= $searchedStudent['total_mark'] ?></td>
        </tr>
    </table>
<?php endif; ?>

</div>
</body>
</html>
