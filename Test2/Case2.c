Case2()
{
	//int cnt;
	/* itinerary */

	//lr_think_time(42);
	
web_reg_save_param_ex(
		"ParamName=Price",
    "LB/IC=Total Charge: $ ",
    "RB/IC= <BR/>",
    "Ordinal=1",
	LAST);
	
	web_reg_save_param_ex(
		"ParamName=Class",
    "LB/IC=<b>&nbsp;",
    "RB/IC= First class",
    "Ordinal=all",
    "NotFound=Warning",
	LAST);
	
	

	web_url("welcome.pl", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

lr_output_message("The price of the first ticket is equal to %s", lr_eval_string("{Price}"));
lr_output_message("The number of first class tickets is equal to %d",atoi(lr_eval_string("{Class_count}")));
	
	return 0;
}
