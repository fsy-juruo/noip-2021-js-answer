#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[200010]={150011,150019,150029,150041,150049,150053,150055,150061,150063,150065,150069,150083,150089,150091,150099,150113,150125,150131,150139,150145,150149,150151,150153,150155,150159,150163,150169,150189,150193,150203,150209,150211,150215,150221,150223,150239,150243,150293,150295,150299,150301,150303,150313,150323,150329,150333,150341,150343,150349,150359,150369,150383,150389,150391,150393,150401,150413,150419,150421,150429,150431,150439,150445,150455,150459,150481,150491,150503,150509,150515,150523,150529,150533,150545,150551,150559,150565,150583,150589,150595,150601,150609,150611,150623,150625,150629,150649,150655,150659,150663,150665,150691,150693,150695,150805,150809,150833,150845,150851,150869,150881,150883,150889,150893,150901,150905,150911,150915,150919,150929,150933,150949,150959,150961,150963,150989,150991,150995,150999,151009,151013,151015,151023,151043,151049,151051,151055,151061,151089,151091,151103,151115,151121,151139,151141,151149,151153,151163,151169,151189,151201,151205,151211,151213,151229,151233,151241,151243,151245,151253,151265,151269,151289,151295,151299,151303,151309,151321,151323,151325,151331,151339,151343,151345,151359,151363,151369,151381,151383,151391,151399,151423,151429,151433,151451,151465,151483,151499,151509,151523,151531,151539,151545,151549,151553,151559,151561,151565,151595,151603,151609,151615,151625,151629,151631,151633,151643,151645,151649,151651,151653,151665,151681,151693,151699,151813,151831,151841,151849,151853,151859,151883,151899,151901,151903,151909,151915,151919,151939,151945,151953,151955,151969,151993,151995,152003,152009,152015,152021,152029,152039,152041,152049,152053,152063,152081,152083,152093,152095,152105,152111,152119,152123,152129,152141,152143,152149,152155,152183,152189,152195,152203,152209,152213,152219,152221,152225,152231,152239,152245,152249,152251,152263,152293,152309,152311,152339,152345,152353,152359,152363,152381,152389,152393,152409,152419,152423,152429,152441,152443,152445,152449,152455,152459,152461,152463,152465,152489,152491,152493,152499,152501,152519,152525,152531,152533,152539,152543,152545,152563,152569,152583,152591,152599,152611,152615,152623,152629,152639,152641,152645,152653,152681,152683,152695,152809,152819,152821,152823,152825,152829,152833,152839,152843,152849,152851,152853,152861,152869,152899,152909,152911,152923,152933,152939,152941,152953,152959,152963,152965,152981,152989,152993,153001,153003,153015,153019,153025,153043,153059,153061,153089,153093,153103,153109,153113,153121,153129,153131,153133,153145,153149,153151,153155,153165,153183,153191,153199,153203,153211,153215,153233,153239,153241,153245,153249,153253,153259,153263,153269,153281,153305,153311,153313,153319,153325,153329,153343,153345,153353,153359,153383,153393,153399,153409,153413,153415,153421,153443,153445,153449,153453,153469,153481,153483,153499,153509,153511,153521,153523,153529,153533,153539,153563,153569,153581,153583,153589,153593,153609,153611,153619,153623,153641,153649,153669,153683,153689,153691,153803,153823,153829,153841,153849,153859,153863,153869,153889,153893,153911,153913,153919,153929,153931,153941,153949,153953,153959,153961,153983,153989,153991,154001,154013,154015,154023,154025,154029,154039,154043,154045,154055,154061,154069,154081,154083,154093,154099,154109,154111,154121,154145,154149,154151,154153,154159,154165,154181,154183,154195,154205,154211,154213,154219,154229,154239,154243,154255,154263,154265,154291,154293,154295,154303,154313,154319,154321,154333,154339,154345,154351,154363,154369,154383,154391,154393,154405,154409,154423,154429,154439,154443,154459,154463,154465,154481,154493,154495,154499,154501,154509,154515,154519,154523,154533,154543,154545,154555,154561,154563,154589,154591,154613,154619,154621,154631,154639,154643,154653,154655,154659,154669,154681,154689,154691,154695,154699,154811,154815,154823,154831,154839,154841,154849,154883,154891,154893,154901,154913,154915,154929,154933,154943,154963,154965,154969,154981,154991,154995,154999,155003,155005,155009,155045,155049,155059,155065,155069,155081,155083,155093,155095,155111,155119,155123,155129,155153,155161,155165,155189,155191,155195,155201,155203,155209,155219,155231,155233,155243,155245,155251,155255,155269,155291,155299,155303,155315,155333,155339,155341,155345,155359,155369,155381,155383,155389,155399,155405,155409,155413,155423,155443,155453,155455,155461,155489,155501,155509,155521,155525,155539,155545,155559,155569,155581,155591,155593,155599,155605,155609,155611,155615,155621,155629,155633,155639,155651,155653,155663,155665,155681,155683,155689,155693,155695,155699,155801,155809,155815,155819,155821,155823,155833,155843,155849,155851,155861,155863,155891,155893,155905,155915,155921,155923,155945,155959,155965,155983,155989,156011,156013,156019,156039,156041,156045,156049,156053,156059,156061,156063,156089,156095,156099,156109,156115,156119,156125,156131,156133,156139,156143,156151,156153,156155,156161,156169,156199,156203,156209,156211,156229,156241,156243,156245,156253,156259,156265,156269,156283,156295,156299,156301,156309,156319,156329,156353,156361,156363,156389,156409,156419,156421,156431,156433,156449,156459,156469,156489,156491,156493,156495,156509,156511,156515,156521,156523,156533,156539,156543,156545,156549,156559,156581,156589,156593,156595,156599,156601,156603,156605,156619,156623,156629,156631,156641,156643,156649,156659,156661,156665,156669,156683,156691,156805,156811,156823,156829,156833,156841,156851,156853,156869,156881,156889,156899,156901,156903,156913,156929,156931,156939,156941,156943,156945,156955,156963,156965,158003,158005,158009,158021,158029,158051,158059,158063,158065,158069,158089,158093,158113,158119,158129,158131,158141,158143,158159,158161,158189,158195,158201,158203,158209,158215,158225,158231,158233,158239,158243,158245,158251,158255,158261,158269,158293,158299,158303,158309,158315,158329,158339,158341,158351,158359,158363,158381,158383,158393,158399,158411,158419,158429,158433,158439,158441,158443,158449,158453,158469,158489,158495,158503,158513,158519,158521,158539,158551,158563,158581,158583,158591,158609,158611,158621,158633,158639,158649,158651,158653,158663,158689,158699,158803,158819,158829,158839,158843,158849,158853,158863,158881,158889,158903,158909,158923,158929,158939,158941,158943,158953,158959,158981,158993,159009,159011,159013,159015,159023,159025,159029,159031,159045,159053,159059,159101,159113,159115,159119,159121,159133,159139,159149,159153,159155,159161,159169,159191,159193,159195,159199,159209,159223,159233,159241,159245,159263,159265,159281,159289,159293,159295,159301,159303,159311,159319,159329,159339,159349,159361,159389,159391,159403,159415,159419,159421,159423,159431,159449,159455,159459,159461,159463,159465,159469,159483,159491,159499,159503,159515,159521,159529,159533,159539,159541,159553,159563,159569,159583,159589,159599,159603,159609,159623,159629,159631,159643,159653,159665,159683,159689,159693,159699,159805,159811,159815,159823,159833,159839,159841,159843,159853,159863,159869,159881,159883,159889,159899,159905,159909,159911,159913,159931,159945,159955,159959,159961,159969,159989,159995,160000,160001,160009,160010,160015,160018,160019,160023,160024,160030,160031,160033,160036,160039,160040,160042,160045,160049,160051,160052,160058,160059,160061,160066,160081,160084,160086,160088,160091,160093,160096,160098,160100,160102,160103,160109,160115,160120,160124,160141,160143,160145,160151,160159,160163,160165,160166,160168,160169,160180,160183,160184,160189,160190,160192,160193,160199,160201,160203,160211,160213,160219,160220,160222,160229,160231,160232,160233,160238,160240,160243,160249,160250,160252,160253,160255,160256,160269,160282,160289,160295,160298,160306,160309,160313,160315,160319,160322,160323,160329,160330,160343,160345,160351,160359,160366,160382,160396,160399,160400,160403,160408,160409,160415,160418,160423,160430,160439,160441,160442,160444,160445,160450,160453,160459,160462,160466,160481,160483,160492,160495,160499,160501,160502,160504,160509,160513,160516,160520,160523,160525,160526,160541,160553,160583,160586,160589,160591,160595,160603,160604,160606,160609,160610,160612,160613,160618,160619,160621,160630,160631,160639,160640,160642,160645,160649,160651,160652,160653,160658,160663,160669,160681,160682,160690,160801,160805,160806,160808,160813,160822,160829,160831,160833,160840,160841,160843,160852,160858,160859,160861,160869,160883,160889,160891,160898,160899,160900,160903,160904,160910,160915,160918,160919,160924,160926,160932,160933,160945,160955,160959,160960,160963,160964,160966,160969,160981,160982,160984,160989,160991,160998,160999,161003,161009,161012,161015,161026,161029,161030,161032,161033,161039,161043,161045,161048,161050,161051,161052,161053,161059,161060,161065,161083,161089,161093,161095,161110,161123,161125,161131,161132,161141,161149,161159,161162,161165,161180,161183,161191,161192,161195,161198,161201,161206,161212,161213,161218,161219,161221,161222,161225,161233,161242,161243,161255,161258,161261,161263,161281,161284,161288,161300,161302,161303,161305,161309,161323,161324,161333,161338,161339,161341,161359,161362,161363,161366,161369,161389,161393,161405,161411,161419,161429,161439,161453,161459,161461,161493,161495,161499,161501,161503,161513,161515,161519,161521,161531,161533,161543,161545,161561,161563,161569,161583,161589,161591,161599,161600,161603,161605,161606,161608,161611,161615,161618,161620,161629,161632,161638,161639,161641,161643,161645,161648,161650,161659,161662,161663,161666,161669,161683,161689,161692,161696,161698,161815,161818,161822,161830,161831,161836,161839,161842,161845,161846,161848,161849,161853,161858,161859,161863,161864,161866,161869,161881,161886,161899,161905,161906,161911,161918,161921,161923,161926,161929,161930,161932,161933,161960,161969,161983,161984,161992,161996,161999,162002,162003,162004,162005,162011,162020,162025,162026,162031,162033,162038,162039,162040,162046,162053,162055,162059,162062,162065,162080,162082,162086,162088,162089,162091,162098,162100,162109,162115,162116,162119,162124,162128,162130,162139,162143,162145,162161,162166,162199,162202,162205,162209,162215,162220,162221,162223,162229,162230,162233,162236,162238,162241,162249,162251,162256,162262,162263,162269,162286,162289,162290,162293,162301,162303,162310,162320,162326,162332,162339,162343,162359,162362,162363,162364,162369,162383,162389,162391,162398,162399,162406,162409,162413,162416,162419,162436,162439,162440,162443,162445,162446,162451,162453,162455,162458,162460,162465,162466,162483,162489,162490,162493,162499,162500,162502,162506,162509,162515,162521,162523,162524,162529,162530,162538,162539,162543,162549,162553,162559,162562,162563,162566,162584,162586,162592,162593,162595,162598,162601,162608,162611,162623,162625,162629,162641,162643,162649,162650,162653,162655,162662,162664,162665,162683,162686,162691,162695,162698,162802,162805,162815,162818,162821,162823,162829,162833,162838,162839,162842,162845,162853,162859,162881,162889,162901,162905,162913,162915,162923,162926,162933,162943,162959,162965,162969,162989,162991,162993,163003,163010,163015,163018,163019,163021,163025,163031,163033,163039,163045,163049,163055,163061,163063,163066,163083,163089,163091,163102,163105,163106,163109,163118,163126,163129,163138,163141,163151,163165,163169,163181,163189,163190,163193,163199,163203,163204,163209,163211,163216,163220,163222,163223,163225,163232,163238,163239,163243,163245,163246,163249,163250,163252,163258,163259,163263,163264,163265,163288,163292,163295,163298,163309,163316,163321,163329,163330,163351,163361,163363,163364,163381,163382,163383,163391,163393,163396,163399,163403,163409,163411,163433,163439,163465,163469,163481,163483,163509,163519,163529,163531,163543,163549,163559,163561,163563,163589,163601,163612,163613,163616,163619,163621,163623,163629,163633,163643,163652,163661,163663,163689,163699,163801,163802,163803,163804,163811,163813,163819,163822,163823,163826,163838,163839,163841,163844,163853,163858,163859,163861,163862,163864,163869,163883,163886,163893,163899,163901,163903,163906,163909,163918,163923,163928,163929,163943,163951,163963,163969,163981,163991,163993,164000,164005,164006,164009,164011,164012,164015,164018,164023,164026,164029,164039,164041,164042,164044,164048,164051,164060,164062,164069,164086,164089,164090,164092,164093,164096,164102,164110,164111,164113,164123,164125,164149,164153,164155,164159,164165,164168,164180,164183,164189,164191,164195,164198,164200,164201,164204,164209,164210,164215,164219,164224,164225,164231,164233,164239,164240,164246,164249,164251,164258,164264,164282,164291,164299,164303,164306,164309,164321,164324,164326,164329,164330,164333,164341,164345,164363,164366,164386,164389,164392,164393,164398,164401,164405,164408,164410,164413,164419,164420,164429,164431,164438,164440,164443,164446,164449,164452,164455,164461,164462,164482,164489,164499,164503,164504,164506,164510,164513,164515,164518,164522,164524,164525,164529,164530,164531,164533,164545,164553,164555,164564,164569,164581,164589,164593,164596,164599,164602,164603,164618,164620,164621,164623,164629,164630,164638,164639,164642,164643,164644,164653,164656,164659,164660,164663,164665,164666,164683,164695,164698,164699,164804,164809,164810,164812,164813,164816,164819,164821,164823,164830,164831,164833,164839,164842,164845,164848,164852,164858,164861,164881,164884,164888,164891,164893,164896,164902,164903,164911,164915,164918,164924,164926,164929,164930,164932,164938,164939,164945,164949,164953,164959,164960,164963,164965,164966,164981,164984,164986,164989,164995,164998,164999,165001,165003,165008,165009,165010,165013,165040,165041,165043,165045,165049,165050,165052,165055,165058,165059,165062,165063,165065,165069,165083,165089,165091,165098,165099,165103,165106,165115,165118,165119,165122,165124,165125,165128,165133,165136,165143,165145,165149,165153,165160,165161,165169,165181,165182,165183,165190,165196,165202,165203,165211,165212,165218,165226,165229,165233,165236,165238,165241,165245,165248,165250,165253,165259,165260,165262,165265,165266,165280,165281,165290,165293,165296,165302,165304,165309,165311,165313,165320,165322,165323,165328,165331,165332,165341,165343,165349,165363,165364,165383,165391,165398,165409,165413,165415,165419,165443,165449,165453,165455,165463,165469,165489,165499,165511,165523,165533,165539,165541,165545,165551,165553,165559,165565,165569,165583,165589,165593,165595,165601,165603,165605,165609,165610,165611,165622,165625,165626,165629,165639,165644,165650,165652,165653,165693,165695,165805,165806,165811,165812,165820,165826,165829,165833,165838,165839,165842,165845,165881,165883,165901,165905,165911,165913,165926,165931,165939,165941,165943,165953,165955,165961,165962,165964,165983,165993,165995,165999,166001,166006,166009,166013,166015,166018,166021,166029,166030,166031,166043,166045,166046,166052,166053,166055,166059,166063,166066,166081,166084,166091,166099,166105,166109,166111,166115,166118,166126,166132,166139,166143,166149,166151,166162,166169,166183,166186,166189,166190,166196,166202,166219,166220,166233,166238,166245,166246,166249,166255,166259,166262,166265,166289,166301,166303,166310,166319,166321,166323,166325,166329,166330,166331,166339,166349,166351,166363,166366,166393,166399,166400,166403,166406,166409,166412,166415,166423,166429,166436,166438,166441,166442,166444,166445,166448,166450,166462,166466,166480,166484,166486,166490,166493,166503,166504,166505,166510,166511,166525,166528,166529,166531,166533,166538,166541,166553,166555,166559,166561,166564,166580,166598,166601,166603,166604,166609,166610,166613,166619,166622,166623,166631,166633,166636,166639,166640,166643,166645,166655,166660,166661,166664,166669,166682,166683,166689,166693,166695,166699,166802,166809,166811,166823,166829,166841,166843,166846,166849,166853,166861,166862,166863,166869,166882,166883,166886,166893,166898,166899,166909,166910,166913,166918,166919,166930,166931,166933,166939,166949,166955,166961,166963,166965,166966,166983,166989,166990,168005,168006,168008,168009,168013,168016,168018,168019,168022,168023,168029,168040,168043,168052,168053,168059,168060,168064,168065,168083,168088,168089,168092,168095,168104,168106,168109,168110,168115,168118,168121,168122,168123,168131,168132,168138,168143,168145,168149,168151,168159,168160,168180,168184,168186,168193,168195,168205,168208,168209,168211,168218,168221,168229,168230,168233,168242,168243,168244,168248,168251,168253,168262,168263,168269,168281,168286,168289,168290,168293,168303,168305,168306,168310,168319,168320,168323,168326,168331,168332,168333,168339,168353,168359,168361,168362,168369,168382,168389,168391,168393,168396,168398,168404,168409,168415,168422,168423,168430,168433,168440,168442,168443,168446,168449,168451,168458,168460,168463,168464,168465,168466,168481,168486,168488,168491,168496,168499,168506,168509,168512,168523,168524,168526,168533,168541,168551,168559,168569,168583,168593,168598,168599,168601,168612,168619,168622,168626,168629,168631,168638,168641,168643,168653,168666,168689,168698,168699,168802,168803,168808,168809,168818,168821,168836,168839,168841,168842,168851,168859,168862,168863,168869,168881,168883,168884,168886,168892,168893,168898,168899,168901,168906,168913,168919,168926,168933,168943,168949,168962,168968,168991,168992,168996,168998,168999,169003,169006,169009,169010,169013,169018,169019,169030,169033,169039,169040,169042,169045,169046,169049,169052,169055,169063,169066,169069,169086,169093,169098,169102,169105,169109,169111,169118,169121,169123,169124,169126,169129,169130,169132,169138,169145,169149,169151,169159,169160,169166,169181,169189,169192,169196,169199,169203,169206,169210,169213,169219,169220,169222,169226,169229,169230,169240,169241,169243,169244,169249,169255,169258,169259,169262,169266,169283,169289,169292,169293,169298,169301,169304,169306,169310,169313,169315,169318,169319,169321,169324,169329,169331,169333,169339,169343,169359,169361,169369,169382,169383,169396,169399,169409,169411,169415,169429,169445,169453,169465,169483,169489,169493,169495,169499,169501,169503,169509,169523,169531,169539,169543,169549,169553,169555,169559,169565,169583,169591,169593,169599,169612,169615,169616,169618,169621,169622,169629,169630,169633,169636,169639,169640,169649,169651,169655,169658,169661,169665,169669,169681,169688,169691,169693,169696,169698,169699,169804,169805,169808,169810,169815,169819,169823,169826,169829,169831,169833,169836,169838,169843,169844,169846,169852,169859,169863,169882,169889,169891,169899,169909,169913,169919,169922,169930,169931,169933,169943,169945,169951,169959,169961,169964,169969,169980,169982,169984,169989,169991,169996,180001,180002,180004,180008,180016,180020,180022,180023,180031,180038,180039,180043,180045,180046,180049,180052,180053,180055,180059,180060,180062,180065,180066,180080,180088,180095,180099,180106,180118,180119,180121,180123,180130,180133,180139,180143,180160,180161,180165,180181,180189,180191,180202,180203,180211,180212,180220,180221,180233,180239,180241,180242,180244,180248,180249,180259,180260,180263,180265,180281,180289,180298,180303,180305,180309,180311,180322,180326,180328,180329,180330,180331,180332,180361,180382,180391,180392,180396,180398,180399,180406,180409,180410,180413,180415,180419,180430,180451,180459,180463,180466,180483,180484,180490,180491,180503,180511,180512,180520,180521,180524,180526,180533,180539,180541,180545,180562,180563,180569,180580,180581,180589,180590,180595,180598,180599,180605,180610,180615,180618,180620,180623,180626,180629,180631,180636,180638,180640,180641,180643,180644,180645,180646,180653,180655,180658,180660,180664,180669,180682,180683,180802,180805,180806,180811,180818,180820,180832,180839,180844,180851,180853,180862,180869,180883,180884,180889,180892,180896,180898,180899,180902,180904,180909,180911,180913,180916,180920,180926,180932,180938,180939,180945,180949,180955,180959,180961,180962,180966,180968,180980,180983,180986,180990,180993,180995,180996,180998,181001,181003,181009,181015,181018,181019,181022,181029,181030,181031,181036,181039,181042,181045,181046,181049,181052,181058,181059,181060,181061,181063,181066,181081,181082,181086,181098,181103,181105,181106,181109,181120,181123,181124,181126,181129,181133,181136,181141,181145,181149,181166,181180,181183,181190,181193,181198,181199,181201,181205,181208,181210,181211,181212,181213,181218,181219,181238,181239,181241,181243,181245,181249,181252,181253,181255,181261,181262,181264,181266,181282,181283,181289,181290,181291,181301,181303,181310,181312,181313,181315,181316,181318,181319,181329,181330,181338,181343,181345,181351,181361,181364,181381,181389,181399,181403,181409,181421,181423,181439,181443,181445,181449,181451,181459,181465,181469,181495,181499,181501,181511,181513,181515,181519,181523,181533,181549,181553,181555,181563,181565,181595,181599,181603,181606,181609,181612,181613,181619,181630,181639,181642,181646,181652,181653,181666,181669,181682,181690,181691,181693,181695,181801,181802,181803,181809,181810,181813,181819,181820,181822,181829,181833,181836,181852,181862,181869,181882,181889,181891,181893,181901,181903,181910,181913,181915,181918,181919,181921,181924,181931,181932,181933,181938,181939,181943,181945,181949,181959,181964,181969,181981,181983,181990,181995,181998,182005,182009,182011,182012,182018,182023,182029,182038,182041,182046,182059,182060,182065,182066,182081,182083,182086,182089,182092,182093,182099,182101,182110,182111,182122,182123,182129,182131,182132,182141,182143,182159,182162,182164,182165,182180,182195,182198,182201,182204,182209,182212,182215,182230,182233,182239,182242,182243,182246,182251,182255,182258,182261,182269,182282,182290,182293,182302,182305,182306,182309,182311,182318,182326,182330,182333,182339,182341,182345,182353,182363,182366,182381,182386,182389,182396,182398,182402,182405,182408,182409,182415,182418,182419,182423,182429,182431,182433,182438,182440,182443,182445,182446,182449,182452,182453,182458,182460,182463,182465,182480,182486,182488,182489,182491,182498,182503,182506,182509,182510,182519,182523,182524,182530,182538,182545,182549,182555,182559,182561,182564,182566,182582,182586,182589,182593,182599,182603,182605,182606,182608,182615,182618,182629,182633,182636,182639,182641,182645,182653,182659,182660,182662,182663,182681,182690,182695,182803,182809,182810,182813,182815,182821,182822,182829,182831,182839,182842,182846,182849,182851,182859,182866,182881,182883,182893,182899,182906,182911,182915,182918,182921,182926,182929,182930,182933,182939,182941,182951,182953,182963,182969,182981,182983,182986,182989,182990,182993,182995,182998,182999,183003,183009,183010,183019,183023,183026,183030,183041,183045,183049,183053,183055,183058,183059,183061,183069,183082,183083,183086,183089,183091,183093,183095,183098,183110,183115,183119,183121,183129,183130,183139,183145,183151,183153,183161,183163,183165,183166,183182,183191,183203,183205,183208,183212,183215,183220,183223,183229,183238,183242,183258,183259,183262,183263,183265,183266,183269,183283,183284,183286,183289,183290,183292,183299,183301,183304,183305,183315,183318,183319,183320,183329,183331,183332,183338,183341,183343,183349,183353,183361,183363,183364,183368,183382,183383,183389,183399,183415,183419,183423,183431,183433,183439,183445,183451,183453,183455,183459,183461,183493,183499,183503,183509,183511,183523,183529,183539,183541,183551,183559,183569,183581,183593,183601,183602,183611,183613,183618,183619,183622,183623,183626,183633,183636,183641,183644,183646,183658,183661,183669,183682,183683,183688,183689,183691,183693,183699,183802,183803,183809,183812,183818,183823,183829,183836,183842,183849,183856,183858,183859,183881,183886,183902,183913,183919,183922,183926,183929,183938,183941,183943,183949,183959,183962,183966,183969,183989,183993,183999,184003,184006,184010,184013,184018,184021,184022,184024,184029,184031,184039,184043,184045,184046,184048,184055,184060,184066,184081,184082,184084,184088,184089,184090,184091,184098,184102,184105,184109,184111,184115,184120,184123,184126,184130,184133,184138,184139,184141,184143,184145,184153,184159,184165,184166,184168,184169,184180,184181,184189,184190,184196,184199,184204,184209,184211,184213,184215,184222,184231,184232,184238,184241,184244,184253,184258,184259,184286,184291,184298,184306,184309,184315,184321,184323,184328,184330,184333,184336,184343,184351,184364,184369,184389,184396,184403,184406,184409,184411,184412,184420,184423,184424,184430,184438,184439,184441,184442,184449,184460,184462,184463,184466,184469,184486,184489,184495,184498,184502,184504,184505,184510,184511,184515,184516,184523,184532,184533,184538,184543,184553,184559,184564,184565,184582,184595,184598,184609,184610,184612,184615,184619,184622,184629,184631,184633,184645,184648,184649,184651,184655,184659,184664,184666,184669,184683,184689,184693,184801,184802,184809,184810,184812,184816,184818,184819,184820,184823,184826,184829,184830,184831,184838,184839,184840,184843,184844,184845,184859,184861,184862,184866,184883,184893,184901,184903,184910,184913,184915,184916,184918,184921,184922,184929,184930,184931,184949,184953,184959,184966,184969,184980,184993,184995,184998,184999,185006,185009,185012,185021,185023,185029,185032,185033,185043,185044,185046,185048,185051,185053,185063,185069,185089,185099,185102,185119,185123,185126,185131,185138,185141,185149,185153,185159,185161,185162,185183,185186,185189,185191,185204,185209,185218,185219,185221,185233,185236,185243,185246,185251,185261,185263,185281,185282,185284,185291,185299,185303,185306,185309,185323,185338,185359,185362,185363,185366,185369,185386,185396,185398,185401,185411,185429,185439,185441,185443,185483,185491,185499,185501,185503,185519,185529,185531,185533,185539,185543,185551,185559,185569,185583,185593,185599,185602,185608,185609,185618,185621,185624,185632,185638,185641,185642,185644,185646,185648,185651,185653,185659,185662,185663,185681,185683,185693,185698,185699,185804,185806,185809,185812,185813,185819,185821,185831,185833,185842,185846,185849,185853,185863,185869,185881,185882,185883,185891,185893,185898,185902,185903,185911,185918,185921,185923,185933,185936,185938,185939,185943,185951,185959,185984,185986,185989,185993,185996,185998,186002,186008,186009,186013,186016,186019,186022,186023,186033,186041,186043,186044,186049,186058,186062,186064,186083,186092,186101,186103,186106,186113,186118,186119,186122,186128,186129,186131,186132,186139,186149,186153,186159,186161,186163,186164,186166,186169,186191,186196,186198,186199,186206,186209,186211,186226,186229,186236,186239,186241,186243,186244,186253,186259,186262,186266,186283,186289,186299,186301,186302,186306,186311,186313,186323,186328,186329,186338,186341,186343,186353,186364,186391,186392,186393,186398,186404,186409,186413,186418,186419,186423,186429,186433,186451,186458,186469,186481,186482,186483,186486,186488,186492,186502,186503,186506,186509,186526,186532,186533,186549,186551,186553,186562,186566,186568,186569,186581,186583,186584,186589,186593,186596,186601,186603,186604,186611,186612,186619,186623,186629,186636,186638,186639,186644,186646,186649,186652,186653,186658,186664,186682,186689,186699,186811,186818,186829,186833,186838,186841,186843,186859,186866,186869,186883,186889,186899,186906,186909,186911,186918,186922,186923,186926,186933,186938,186941,186959,186962,186969,186982,186986,188009,188011,188018,188021,188026,188029,188038,188049,188053,188059,188063,188066,188081,188098,188113,188119,188126,188131,188138,188143,188159,188186,188189,188198,188218,188222,188231,188239,188242,188246,188249,188261,188269,188281,188291,188299,188302,188303,188306,188311,188323,188333,188338,188339,188351,188359,188369,188389,188393,188399,188401,188402,188403,188409,188429,188431,188438,188443,188458,188459,188466,188483,188491,188506,188509,188519,188522,188533,188539,188549,188553,188563,188582,188583,188593,188599,188602,188603,188609,188618,188621,188633,188642,188651,188653,188662,188669,188681,188686,188689,188693,188698,188801,188809,188813,188821,188822,188829,188831,188833,188842,188843,188861,188863,188866,188869,188882,188886,188891,188899,188911,188918,188926,188929,188933,188939,188941,188943,188949,188953,188963,188966,188983,188999,189009,189011,189018,189019,189022,189026,189029,189031,189038,189039,189041,189043,189058,189059,189061,189062,189066,189082,189083,189086,189093,189099,189106,189109,189118,189122,189131,189139,189149,189151,189163,189166,189169,189186,189199,189206,189209,189223,189226,189229,189239,189242,189246,189251,189253,189258,189281,189293,189298,189302,189309,189311,189313,189319,189323,189326,189331,189338,189339,189341,189349,189353,189359,189361,189386,189389,189391,189393,189401,189421,189433,189439,189461,189463,189481,189491,189493,189503,189509,189523,189529,189549,189559,189569,189583,189589,189593,189599,189606,189613,189619,189622,189633,189638,189643,189646,189649,189653,189659,189661,189682,189683,189689,189691,189698,189806,189823,189841,189843,189851,189853,189858,189859,189862,189866,189869,189881,189898,189899,189901,189902,189906,189909,189913,189922,189929,189933,189939,189949,189953,189961,189962,189983,189986,189989,189993,189998,190006,190010,190018,190030,190031,190039,190042,190045,190049,190051,190055,190059,190061,190063,190081,190082,190083,190089,190090,190093,190103,190109,190118,190121,190123,190126,190129,190130,190159,190166,190181,190186,190189,190195,190198,190199,190202,190219,190222,190229,190231,190243,190249,190259,190261,190262,190263,190265,190283,190286,190301,190306,190310,190313,190318,190319,190321,190329,190331,190339,190343,190345,190363,190369,190381,190382,190389,190391,190403,190406,190409,190415,190418,190426,190429,190433,190438,190445,190462,190466,190486,190489,190490,190495,190501,190510,190511,190522,190523,190529,190543,190549,190562,190563,190565,190583,190591,190595,190599,190609,190613,190618,190622,190623,190633,190639,190643,190649,190669,190681,190690,190691,190693,190699,190802,190803,190805,190810,190811,190818,190823,190826,190829,190833,190838,190843,190849,190858,190882,190886,190889,190891,190899,190901,190906,190909,190913,190915,190921,190922,190929,190930,190933,190945,190955,190959,190963,190966,190989,190991,190999,191005,191006,191018,191021,191033,191038,191039,191042,191045,191049,191053,191062,191066,191089,191095,191098,191099,191110,191119,191122,191123,191129,191138,191141,191143,191153,191155,191159,191161,191162,191183,191189,191195,191206,191210,191231,191239,191242,191245,191249,191251,191255,191258,191263,191266,191281,191293,191299,191302,191305,191306,191309,191311,191315,191329,191339,191341,191353,191393,191398,191405,191409,191413,191441,191449,191453,191459,191461,191469,191489,191491,191495,191509,191515,191519,191523,191531,191533,191545,191551,191559,191561,191563,191589,191599,191602,191605,191606,191621,191626,191630,191638,191645,191665,191669,191683,191689,191690,191693,191699,191801,191803,191809,191810,191813,191819,191822,191830,191831,191833,191846,191858,191859,191861,191869,191881,191886,191899,191902,191903,191909,191911,191915,191918,191923,191929,191938,191951,191953,191959,191962,191965,191966,191969,191999,192001,192002,192008,192012,192013,192018,192019,192020,192026,192029,192039,192040,192041,192043,192048,192053,192061,192064,192069,192086,192091,192092,192099,192103,192106,192109,192110,192113,192116,192118,192119,192120,192121,192130,192131,192133,192138,192145,192149,192155,192160,192161,192169,192180,192184,192189,192190,192191,192193,192196,192198,192221,192226,192229,192232,192233,192239,192242,192243,192245,192249,192251,192259,192260,192263,192264,192265,192281,192293,192295,192298,192299,192305,192306,192310,192315,192319,192320,192323,192328,192329,192331,192333,192341,192343,192345,192349,192359,192362,192364,192369,192383,192391,192392,192396,192398,192403,192422,192431,192436,192442,192443,192446,192449,192453,192455,192459,192460,192461,192463,192464,192466,192480,192484,192488,192490,192495,192498,192499,192502,192503,192505,192506,192509,192518,192520,192524,192526,192529,192538,192539,192541,192553,192562,192569,192580,192581,192583,192586,192589,192590,192595,192601,192609,192611,192613,192615,192620,192629,192630,192631,192641,192646,192649,192652,192656,192658,192662,192664,192669,192683,192693,192802,192803,192805,192809,192811,192818,192820,192824,192833,192838,192845,192846,192849,192851,192853,192858,192859,192862,192869,192883,192884,192886,192889,192898,192902,192903,192904,192909,192910,192922,192923,192928,192931,192938,192943,192949,192959,192961,192965,192968,192980,192986,192991,192999,193003,193008,193009,193010,193013,193015,193021,193031,193036,193043,193045,193051,193055,193058,193063,193064,193082,193089,193090,193093,193098,193099,193106,193111,193118,193124,193126,193132,193133,193139,193143,193145,193153,193159,193162,193163,193169,193181,193183,193189,193190,193195,193196,193198,193199,193201,193202,193208,193209,193211,193213,193218,193220,193236,193238,193240,193243,193244,193246,193252,193255,193260,193261,193265,193269,193282,193283,193286,193289,193299,193301,193309,193316,193318,193322,193329,193330,193332,193345,193351,193353,193359,193364,193381,193393,193398,193415,193423,193433,193439,193441,193449,193451,193463,193465,193469,193483,193489,193493,193495,193513,193519,193533,193539,193541,193549,193559,193583,193601,193603,193609,193616,193619,193624,193636,193639,193642,193646,193649,193652,193659,193663,193689,193692,193696,193803,193808,193811,193813,193818,193819,193822,193829,193832,193838,193839,193841,193846,193849,193852,193859,193861,193862,193863,193883,193891,193899,193906,193909,193913,193918,193924,193926,193938,193939,193943,193951,193964,193966,193981,193983,193989,193993,193999,194003,194009,194011,194015,194039,194041,194059,194069,194081,194083,194093,194101,194105,194111,194113,194119,194141,194149,194153,194165,194189,194195,194203,194219,194239,194255,194263,194269,194303,194305,194309,194323,194339,194353,194363,194405,194409,194413,194431,194433,194443,194455,194459,194461,194483,194489,194499,194515,194519,194521,194529,194543,194559,194569,194581,194591,194603,194605,194609,194615,194629,194639,194641,194651,194653,194659,194665,194681,194683,194695,194809,194813,194819,194829,194839,194853,194861,194863,194869,194891,194899,194911,194921,194923,194933,194941,194949,194959,194963,194965,194969,194981,194989,194995,195009,195011,195015,195023,195029,195031,195033,195043,195045,195049,195053,195059,195065,195089,195095,195099,195103,195115,195121,195131,195133,195145,195159,195161,195163,195169,195189,195193,195203,195205,195215,195229,195233,195241,195243,195253,195259,195269,195281,195295,195303,195311,195319,195329,195331,195333,195341,195343,195353,195359,195369,195383,195389,195401,195403,195413,195423,195429,195443,195445,195451,195469,195491,195493,195495,195505,195509,195511,195515,195523,195539,195541,195549,195553,195565,195581,195583,195593,195595,195599,195609,195623,195639,195641,195645,195659,195665,195689,195691,195695,195803,195805,195809,195815,195821,195851,195863,195869,195883,195893,195905,195913,195919,195929,195931,195945,195955,195969,195983,195991,195995,196003,196006,196012,196013,196016,196018,196019,196022,196030,196033,196036,196039,196043,196045,196046,196048,196051,196052,196059,196060,196081,196082,196089,196090,196099,196106,196111,196115,196120,196123,196124,196132,196138,196139,196143,196145,196149,196159,196160,196162,196165,196166,196169,196181,196183,196186,196192,196193,196195,196199,196201,196202,196205,196208,196219,196220,196239,196241,196246,196249,196255,196256,196258,196264,196269,196283,196286,196289,196291,196298,196303,196309,196313,196318,196323,196324,196331,196369,196382,196389,196408,196411,196412,196415,196426,196429,196436,196439,196442,196445,196451,196453,196459,196463,196465,196481,196484,196489,196492,196495,196496,196499,196501,196502,196505,196509,196519,196523,196529,196531,196538,196541,196543,196545,196549,196555,196561,196563,196565,196569,196580,196583,196598,196610,196613,196615,196629,196633,196640,196642,196643,196646,196652,196653,196659,196660,196661,196663,196681,196689,196699,196804,196806,196810,196815,196816,196818,196822,196829,196831,196832,196838,196841,196844,196849,196853,196858,196863,196886,196888,196891,196892,196899,196901,196904,196906,196909,196915,196918,196919,196921,196923,196929,196932,196943,196949,196953,196960,196961,196964,196969,196982,196984,196986,196989,196990,196991,196993,196998,198001,198005,198006,198010,198013,198020,198022,198026,198029,198031,198036,198038,198041,198043,198046,198059,198060,198066,198069,198082,198083,198091,198092,198095,198106,198109,198110,198115,198116,198123,198124,198129,198130,198131,198133,198138,198139,198143,198151,198155,198159,198165,198166,198181,198183,198190,198193,198196,198206,198218,198221,198223,198230,198236,198238,198241,198242,198249,198251,198259,198262,198263,198266,198269,198281,198286,198295,198298,198299,198301,198309,198311,198313,198318,198319,198323,198329,198330,198343,198349,198362,198363,198364,198382,198389,198391,198399,198409,198410,198412,198413,198416,198418,198419,198430,198433,198439,198440,198446,198449,198451,198452,198455,198459,198460,198461,198463,198465,198466,198469,198482,198483,198491,198495,198496,198498,198502,198503,198518,198524,198529,198532,198533,198539,198551,198553,198566,198568,198581,198584,198586,198589,198593,198598,198599,198602,198608,198613,198619,198623,198631,198636,198638,198641,198649,198652,198659,198663,198682,198686,198689,198691,198698,198802,198811,198818,198823,198829,198833,198839,198841,198851,198859,198862,198893,198899,198901,198902,198903,198906,198911,198929,198931,198938,198939,198941,198943,198953,198959,198966,198983,198999,199018,199021,199022,199029,199033,199039,199046,199049,199051,199058,199069,199081,199083,199086,199089,199090,199099,199102,199103,199105,199109,199118,199126,199130,199145,199149,199151,199153,199162,199165,199166,199169,199181,199190,199193,199195,199201,199204,199205,199209,199210,199211,199216,199218,199222,199236,199239,199244,199246,199249,199261,199265,199266,199286,199289,199292,199293,199298,199299,199301,199303,199309,199310,199313,199315,199321,199322,199324,199328,199330,199331,199338,199343,199345,199349,199351,199366,199369,199383,199384,199389,199399,199403,199405,199411,199415,199429,199441,199453,199463,199481,199483,199489,199499,199501,199505,199513,199519,199523,199543,199553,199559,199569,199583,199589,199595,199599,199601,199603,199610,199613,199618,199621,199622,199623,199624,199629,199630,199639,199643,199645,199646,199649,199658,199659,199663,199666,199669,199684,199690,199693,199695,199698,199802,199803,199805,199806,199811,199812,199813,199819,199826,199830,199831,199838,199840,199845,199846,199853,199856,199858,199859,199866,199889,199909,199910,199915,199918,199919,199921,199922,199924,199929,199930,199931,199932,199933,199939,199945,199951,199959,199960,199961,199964,199965,199968,199980,199981,199982,199986,199991,199993,199996,199999,200000,200002};
int aa[200010];
vector<int>v;
int check(int x){
	for(int i=0;i<v.size();i++){
		if(x%v[i]==0)return 2;
	}
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=150010;i++){
		if(check(i)==0)aa[i]=1;
		else if(check(i)==1)v.push_back(i);
	}
	for(int i=1;i<=50000;i++)aa[a[i]]=1;
	int T;
	read(T);
	while(T--){
		int n;
		read(n);
		if(aa[n]==0){
			cout<<-1<<endl;
		}else if(n==200000){
			cout<<200002<<endl;
		}else{
			int i=n+1;
			while(aa[i]==0){
				i++;
			}
			cout<<i<<endl;
		}
	}
	return 0;
}

