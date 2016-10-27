<!DOCTYPE html>
<html>
    <head>
        <title>Server Test</title>
    </head>
    <body>
        <form action = "" method = "post" enctype = "multipart/form-data">
            select a jpg or png image<br />
	    <input type = "file" name = "image" />
            <input type = "submit" value = "upload" /> <br /><br />
        </form>
        
        <?php
            if(isset($_FILES['image'])) {
                $name = $_FILES['image']['name'];
                move_uploaded_file($_FILES['image']['tmp_name'], 'files\\' . $name);
                echo '<img src = "files/' . $name . '" />';
            }
        ?>
    </body>
</html>

<!--
This simple file upload program works for any file less than 2MB because that is the default max file upload size set in PHP.
To view the default size, run phpinfo() and look for the variable 'upload_max_filesize'.
The default settings are:

upload_max_filesize  2M
post_max_size  8M
memory_limit  128M (irrelevent here)

To change the sizes:

open the php.ini file in xampp/php and change those values and restart the server. The size of post_max_size should be greater than or equal to upload_max_filesize.
-->
