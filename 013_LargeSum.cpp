/*******************************************************************************
* Large Sum
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	unsigned long long int numbers[100] = {
					3710728753390210,
					4637693767749000,
					7432498619952474,
					9194221336357416,
					2306758820753934,
					8926167069662363,
					2811287981284997,
					4427422891743252,
					4745144573600130,
					7038648610584302,
					6217645714185656,
					6490635246274190,
					9257586771833721,
					5820356532535939,
					8018119938482628,
					3539866437282711,
					8651550600629586,
					7169388870771546,
					5437007057682668,
					5328265410875682,
					3612327252500029,
					4587657617241097,
					1742370690585186,
					8114266041808683,
					5193432545172838,
					6246722164843507,
					1573244438690812,
					5503768752567877,
					1833638482533015,
					8038628759287849,
					7818283375799310,
					1672632010043689,
					4840309812907779,
					8708698755139271,
					5995940689575653,
					6979395067965269,
					4105268470829908,
					6537860736150108,
					3582903531743471,
					9495375976510530,
					8890280257173322,
					2526768027607800,
					3627021854049770,
					2407448690823117,
					9143028819710328,
					3441306557801612,
					2305308117281643,
					1148769693215490,
					6378329949063625,
					6772018697169854,
					9554825530026352,
					7608532713228572,
					3777424253541129,
					2370191327572567,
					2979886027225833,
					1849570145487928,
					3829820378303147,
					3482954382919991,
					4095795306640523,
					2974615218550237,
					4169811622207297,
					6246795719440126,
					2318970677254791,
					8618808822587531,
					1130673970830472,
					8295917476714036,
					9762333104481838,
					4284628018351707,
					5512160354698120,
					3223819573432933,
					7550616496518477,
					6217784275219262,
					3292418570714734,
					9951867143023521,
					7326746080059154,
					7684182252467441,
					9714261791034259,
					8778364618279934,
					1084880252167467,
					7132961247478246,
					6218407357239979,
					6662789198148808,
					6066182629368283,
					8578694408955299,
					6602439640990538,
					6491398268003297,
					1673093931987275,
					9480937724504879,
					7863916702118749,
					1536871371193661,
					4078992311553556,
					4488991150144064,
					4150312888033953,
					8123488067321014,
					8261657077394832,
					2291880205877731,
					7715854250201654,
					7210783843506918,
					2084960398013400,
					5350353422647252};
					
	unsigned long long int sum = 0;
	
	for (int i = 0; i < 100; i++)
	{
		sum += numbers[i];
	}
	
	cout << "The first digits of the sum of the numbers is: " << sum << endl;
	
	return 0;
}