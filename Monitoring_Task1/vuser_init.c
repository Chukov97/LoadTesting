vuser_init()
{
	tName = "01.Login_open_field";
	lr_start_transaction(tName);
	
	web_reg_save_param_ex(
    "ParamName=Session", 
    "LB/IC=\"userSession\" value=\"",
    "RB/IC=\"/>",
    "Ordinal=1",
	LAST);

	status=web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	//web_set_sockets_option("SSL_VERSION", "TLS1.2");
	end_transaction(tName, status); //lr_think_time(3);

	/* login */
	tName = "02.Login_fillin_fiels";
	lr_start_transaction(tName);
	
	status=web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={Session}", ENDITEM, 
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=44", ENDITEM, 
		"Name=login.y", "Value=2", ENDITEM, 
		LAST);
	end_transaction(tName, status); //lr_think_time(3);
	return 0;
}
