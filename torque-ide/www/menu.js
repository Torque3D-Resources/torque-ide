//Menu object creation
oCMenu=new makeCM("oCMenu") //Making the menu object. Argument: menuname

oCMenu.frames = 0

//Menu properties   
oCMenu.pxBetween=20
oCMenu.fromLeft=20 
oCMenu.fromTop=0   
oCMenu.rows=1 
oCMenu.menuPlacement="center"
                                                             
oCMenu.offlineRoot="./" 
oCMenu.onlineRoot="/" 
oCMenu.resizeCheck=1 
oCMenu.wait=1000 
oCMenu.fillImg="imgs/cm_fill.gif"
oCMenu.zIndex=0

//Background bar properties
oCMenu.useBar=1
oCMenu.barWidth="98%"
oCMenu.barHeight="menu" 
oCMenu.barClass="clBar"
oCMenu.barX=0 
oCMenu.barY=0
oCMenu.barBorderX=0
oCMenu.barBorderY=0
oCMenu.barBorderClass=""

//Level properties - ALL properties have to be spesified in level 0
oCMenu.level[0]=new cm_makeLevel() //Add this for each new level
oCMenu.level[0].width=110
oCMenu.level[0].height=25 
oCMenu.level[0].regClass="clLevel0"
oCMenu.level[0].overClass="clLevel0over"
oCMenu.level[0].borderX=1
oCMenu.level[0].borderY=1
oCMenu.level[0].borderClass="clLevel0border"
oCMenu.level[0].offsetX=0
oCMenu.level[0].offsetY=0
oCMenu.level[0].rows=0
oCMenu.level[0].arrow=0
oCMenu.level[0].arrowWidth=0
oCMenu.level[0].arrowHeight=0
oCMenu.level[0].align="bottom"

//EXAMPLE SUB LEVEL[1] PROPERTIES - You have to specify the properties you want different from LEVEL[0] - If you want all items to look the same just remove this
oCMenu.level[1]=new cm_makeLevel() //Add this for each new level (adding one to the number)
oCMenu.level[1].width=oCMenu.level[0].width-2
oCMenu.level[1].height=22
oCMenu.level[1].regClass="clLevel1"
oCMenu.level[1].overClass="clLevel1over"
oCMenu.level[1].borderX=1
oCMenu.level[1].borderY=1
oCMenu.level[1].align="right" 
oCMenu.level[1].offsetX=-(oCMenu.level[0].width-2)/2+20
oCMenu.level[1].offsetY=0
oCMenu.level[1].borderClass="clLevel1border"


//EXAMPLE SUB LEVEL[2] PROPERTIES - You have to spesify the properties you want different from LEVEL[1] OR LEVEL[0] - If you want all items to look the same just remove this
oCMenu.level[2]=new cm_makeLevel() //Add this for each new level (adding one to the number)
oCMenu.level[2].width=150
oCMenu.level[2].height=20
oCMenu.level[2].offsetX=0
oCMenu.level[2].offsetY=0
oCMenu.level[2].regClass="clLevel2"
oCMenu.level[2].overClass="clLevel2over"
oCMenu.level[2].borderClass="clLevel2border"


/******************************************
Menu item creation:
myCoolMenu.makeMenu(name, parent_name, text, link, target, width, height, regImage, overImage, regClass, overClass , align, rows, nolink, onclick, onmouseover, onmouseout) 
*************************************/
oCMenu.makeMenu('top0','','&nbsp;Home','http://torque-ide.sourceforge.net/index.html','')

oCMenu.makeMenu('top1','','&nbsp;News','https://sourceforge.net/news/?group_id=128924','')
	
oCMenu.makeMenu('top2','','&nbsp;Screenshots','https://sourceforge.net/project/screenshots.php?group_id=128924')
	
oCMenu.makeMenu('top3','','&nbsp;Sourceforge','https://sourceforge.net/projects/torque-ide/')
	oCMenu.makeMenu('sub31','top3','Summary','https://sourceforge.net/projects/torque-ide/')
	oCMenu.makeMenu('sub32','top3','Tracker','https://sourceforge.net/tracker/?group_id=128924')
	oCMenu.makeMenu('sub33','top3','CVS','https://sourceforge.net/cvs/?group_id=128924')
	oCMenu.makeMenu('sub34','top3','Files','https://sourceforge.net/project/showfiles.php?group_id=128924')
	oCMenu.makeMenu('sub35','top3','Mailing Lists','https://sourceforge.net/mail/?group_id=128924')

oCMenu.makeMenu('top4','','&nbsp;Forums','https://sourceforge.net/forum/?group_id=128924')
	oCMenu.makeMenu('sub40','top4','Help','https://sourceforge.net/forum/forum.php?forum_id=438152')
	oCMenu.makeMenu('sub41','top4','Open Discussion','https://sourceforge.net/forum/forum.php?forum_id=438151')

/**
 * To be used for "DocMan" documentation
 */
/*
oCMenu.makeMenu('top5','','&nbsp;Docs','')
	oCMenu.makeMenu('sub50','top5','Setting up JEdit','docs/setup.html')
	oCMenu.makeMenu('sub51','top5','Compiling','docs/compile.html')
	oCMenu.makeMenu('sub52','top5','Using the plugins','docs/using.html')
	oCMenu.makeMenu('sub53','top5','FAQ','docs/faq.html')
*/

//Leave this line - it constructs the menu
oCMenu.construct()		
