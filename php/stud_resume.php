<!DOCTYPE html>
<html>
<head>
    <title>Student Resume Form</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f7f9fb;
            margin: 0;
            padding: 0;
        }

        h2 {
            text-align: center;
            color: #333;
            margin-top: 30px;
        }

        form {
            background-color: #fff;
            max-width: 450px;
            margin: 30px auto;
            padding: 25px 30px;
            border-radius: 8px;
            box-shadow: 0 4px 10px rgba(0,0,0,0.1);
        }

        label {
            font-weight: bold;
            color: #444;
        }

        input[type="text"],
        input[type="number"],
        input[type="radio"] {
            margin-top: 5px;
        }

        input[type="text"] {
            width: 100%;
            padding: 8px;
            margin-bottom: 15px;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
            font-size: 14px;
        }

        input[type="radio"] {
            margin-right: 5px;
        }

        .button-group {
            text-align: center;
            margin-top: 15px;
        }

        input[type="button"],
        input[type="reset"],
        input[type="submit"] {
            background-color: #007BFF;
            color: white;
            border: none;
            padding: 10px 18px;
            margin: 5px;
            border-radius: 5px;
            cursor: pointer;
            font-size: 14px;
        }

        input[type="button"]:hover,
        input[type="reset"]:hover {
            background-color: #0056b3;
        }

        input[type="reset"] {
            background-color: #6c757d;
        }

        input[type="reset"]:hover {
            background-color: #555;
        }

        input[type="submit"] {
            background-color: #289c38ff;
        }

        input[type="submit"]:hover {
            background-color: #4ef789ff;
        }
    </style>

    <script>
        function calculateTotal() {
            var s1 = parseInt(document.getElementById("sem1").value) || 0;
            var s2 = parseInt(document.getElementById("sem2").value) || 0;
            var s3 = parseInt(document.getElementById("sem3").value) || 0;
            var total = s1 + s2 + s3;
            document.getElementById("total").value = total;
        }

        function validateForm() {
            var name = document.forms["resumeForm"]["name"].value;
            var roll = document.forms["resumeForm"]["roll"].value;
            var gender = document.forms["resumeForm"]["gender"].value;
            var sem1 = document.forms["resumeForm"]["sem1"].value;
            var sem2 = document.forms["resumeForm"]["sem2"].value;
            var sem3 = document.forms["resumeForm"]["sem3"].value;

            if (name == "" || roll == "" || sem1 == "" || sem2 == "" || sem3 == "") {
                alert("All fields are required!");
                return false;
            }

            if (isNaN(sem1) || isNaN(sem2) || isNaN(sem3)) {
                alert("Please enter valid numeric marks for all semesters.");
                return false;
            }

            if (gender == "") {
                alert("Please select gender.");
                return false;
            }

            return true;
        }
    </script>
</head>
<body>
    <h2>Student Resume Form</h2>
    <form name="resumeForm" method="post" action="display_stud_resume.php" onsubmit="return validateForm()">
        <label>Name:</label><br>
        <input type="text" name="name"><br>

        <label>Roll No:</label><br>
        <input type="text" name="roll"><br>

        <label>Gender:</label><br>
        <input type="radio" name="gender" value="Male"> Male &nbsp;
        <input type="radio" name="gender" value="Female"> Female &nbsp;
        <input type="radio" name="gender" value="Other"> Other<br><br>

        <label>Semester 1 Marks:</label><br>
        <input type="text" id="sem1" name="sem1"><br>

        <label>Semester 2 Marks:</label><br>
        <input type="text" id="sem2" name="sem2"><br>

        <label>Semester 3 Marks:</label><br>
        <input type="text" id="sem3" name="sem3"><br>

        <label>Total Marks:</label><br>
        <input type="text" id="total" name="total" readonly><br>

        <div class="button-group">
            <input type="button" value="Calculate Total" onclick="calculateTotal()">
            <input type="reset" value="Reset">
            <input type="submit" value="Submit">
        </div>
    </form>
</body>
</html>
