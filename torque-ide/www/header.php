<?php
// With this latest change (the id being decided by an incremented variable [$page_num]), I most likely will need to change the "correct tab" algorithm
//   to make this more dynamic, heh.
$page_num = 0;
$page[$page_num] = "Summary";
$page_href[$page_num] = "index.php";
$page_num++;
$page[$page_num] = "News";
$page_href[$page_num] = "news.php";
$page_num++;
$page[$page_num] = "Forums";
$page_href[$page_num] = "http://torque-ide.sourceforge.net/phpbb";
$page_num++;
$page[$page_num] = "SourceForge Project";
$page_href[$page_num] = "http://sourceforge.net/projects/torque-ide";
$page_num++;
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<!-- layout by 404 creative studios. http://www.404creative.com -->
<html>
<head>
<title>torque-ide - A TorqueSCRIPT Editor :: <?php echo $page[$page_id]; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta name="keywords" content="Layout2, 404 creative studios" />
<meta name="description" content="simple css driven layout" />
<link href="boldblue2.css" type="text/css" rel="stylesheet" />
</head>
<body>
<div id="container">
	<!-- begin top rounded corner styles -->
	<b class="rtop"><b class="r1"></b><b class="r2"></b> <b class="r3"></b> <b class="r4"></b></b>
	<!-- end top rounded corner styles -->
	<div id="pageHeader">torque-ide - A TorqueSCRIPT Editor</div>
	<div id="divPageContent">
		<div id="navcontainer">
			<ul id="navlist">
<?php
   //<li><a href="index.php">Summary</a></li>
   //<li id="active"><a href="sourceforge.php" id="current">SourceForge Info</a></li>
   for($i=0; $i < count($page); $i++)
   {
      if($i == $page_id)
      {
         $echo = "<li id=\"active\"><a href=\"$page_href[$i]\" id=\"current\">$page[$i]</a></li>";
      }
      else
      {
         $echo = "<li><a href=\"$page_href[$i]\">$page[$i]</a></li>";
      }
      echo $echo;
   }
?>
			</ul>
		</div> 
		<table border="0" cellpadding="5" cellspacing="0">
			<tr>
					<td valign="top" class="leftColumn">
						<div id="sideBarNews">
							<div id="newsHeader">SourceForge.net</div>
							<div id="sideBarNewsContent">
<?php
   include('http://sourceforge.net/export/projhtml.php?group_id=128924&mode=full&no_table=1');
?>
								<!--<div class="newsItem"><a href="index.php">GarageGames</div>
								<div class="readNewsLink">Read More</a></div>-->
                     </div>
						</div>
                  <br /><br /><br />
                  <div align="center"><a href="http://sourceforge.net"><img src="http://sourceforge.net/sflogo.php?group_id=128924&amp;type=5" border="0" alt="SourceForge.net Logo" /></a></div>
					</td>
					<td valign="top" class="rightColumn">
                        <div class="note">This is not to be confused with TIDE, a jEdit plugin that has similar features. <a href="http://torqueide.sourceforge.net">http://torqueide.sourceforge.net</a></div>