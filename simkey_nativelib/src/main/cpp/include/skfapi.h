/** 
* @file skfapi.h
* @brief ��������Կ������Ӧ�ýӿڹ淶��GM/T 0016-2012��
* @author xdja
* @version 1.0.0.1
* @date 20141021
* @note
*/

#ifndef _INC_SKFAPI_H_
#define _INC_SKFAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char	BOOL;//���뱨���ض���
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int   UINT32;

typedef char            CHAR;
typedef signed char     INT8;
typedef signed short    INT16;
typedef signed long     INT32;

#ifdef  TRUE
#undef  TRUE
#endif	/* TRUE */
#define TRUE	1

#ifdef  FALSE
#undef  FALSE
#endif	/* FALSE */
#define FALSE	0

typedef unsigned char   Bool;         /* Boolean                        */

/* Standard typedefs - to retain compatibility with TDMA */
typedef UINT8           		 BYTE;         			/* Unsigned 8-bit quantity        */
typedef UINT8            		 UBYTE;        			/* Unsigned 8-bit quantity        */
typedef UINT16          		 UWORD;        			/* Unsigned 16-bit quantity       */
typedef UINT16          		 WORD;         			/* Unsigned 16-bit quantity       */
typedef INT16           		 SWORD;        			/* Signed 16-bit quantity         */
typedef UINT32                 DWORD;        			/* Unsigned 32-bit quantity       */
typedef unsigned long long     UINT64;                /* Unsigned 64-bit quantity       */
typedef void* 		         VOID_PTR;

#define CONST const

#ifndef TRUE
#define FALSE   0
#define TRUE    1
#endif  /* TRUE */

#ifndef YES
#define YES     TRUE
#define NO      FALSE
#endif  /* YES */

#ifndef ON
#define ON      1
#define OFF     0
#endif

#ifndef PASS
#define PASS      1
#define FAIL     0
#endif

/* A NULL value is required such that it is not mistaken for a valid */
/* value which includes values in the range of modulo 64. */
#define NULL_VAL  0xFF

/* Definition of NULL is required */
#ifndef NULL
#define NULL    0L
#endif  /* NULL */

#ifndef VOID
#define VOID	void
#endif


#define  TY_4G_LTE			 	1
#define  TY_SM2_ENABLE			1
#define  TY_SIMID_AUTH_ENABLE	1
#define  TY_SIMID_TEST			1
#define  TY_CERT_BURN			1
#define  CT_PROJECT_ENABLE		1
#define  TY_SM9_AUTH_ENABLE		1


///������붨���˵��
#define  SAR_OK                           0x00000000     //�ɹ�
#define  SAR_FAIL                         0x0A000001     //ʧ��
#define  SAR_UNKNOWNER                    0x0A000002     //�쳣����		
#define  SAR_NOSUPPORTYETERR              0x0A000003     //��֧�ֵķ���		
#define  SAR_FILEERR                      0x0A000004     //�ļ���������
#define  SAR_INVALIDHANDLEERR             0x0A000005     //��Ч�ľ��
#define  SAR_INVALIDPARAMERR              0x0A000006     //��Ч�Ĳ���		
#define  SAR_READFILEERR                  0x0A000007     //���ļ�����
#define  SAR_WRITEFILEERR                 0x0A000008     //д�ļ�����
#define  SAR_NAMELENERR                   0x0A000009     //���Ƴ��ȴ���
#define  SAR_KEYUSAGEERR                  0x0A00000A     //��Կ��;����
#define  SAR_MODULUSLENERR                0x0A00000B     //ģ�ĳ��ȴ���
#define  SAR_NOTINITIALIZEERR             0x0A00000C     //δ��ʼ��
#define  SAR_OBJERR                       0x0A00000D     //�������
#define  SAR_MEMORYERR                    0x0A00000E     //�ڴ����
#define  SAR_TIMEOUTERR                   0x0A00000F     //��ʱ
#define  SAR_INDATALENERR                 0x0A000010     //�������ݳ��ȴ���	
#define  SAR_INDATAERR                    0x0A000011     //�������ݴ���
#define  SAR_GENRANDERR                   0x0A000012     //�������������
#define  SAR_HASHOBJERR                   0x0A000013     //HASH�������
#define  SAR_HASHERR                      0x0A000014     //HASH�������
#define  SAR_GENRSAKEYERR                 0x0A000015     //����RSA��Կ����
#define  SAR_RSAMODULUSLENERR             0x0A000016     //RSA��Կģ������
#define  SAR_CSPIMPRTPUBKEYERR            0x0A000017     //CSP�����빫Կ����
#define  SAR_RSAENCERR                    0x0A000018     //RSA���ܴ���
#define  SAR_RSADECERR                    0x0A000019     //RSA���ܴ���
#define  SAR_HASHNOTEQUALERR              0x0A00001A     //HASHֵ�����
#define  SAR_KEYNOTFOUNTERR               0x0A00001B     //��Կδ����
#define  SAR_CERTNOTFOUNTERR              0x0A00001C     //֤��δ����
#define  SAR_NOTEXPORTERR                 0x0A00001D     //����δ����
#define  SAR_DECRYPTPADERR                0x0A00001E     //����ʱ����������	
#define  SAR_MACLENERR                    0x0A00001F     //MAC���ȴ���
#define  SAR_BUFFER_TOO_SMALL             0x0A000020     //����������
#define  SAR_KEYINFOTYPRERR               0x0A000021     //��Կ���ʹ���
#define  SAR_NOT_EVENTERR                 0x0A000022     //���¼�����
#define  SAR_DEVICE_REMOVED               0x0A000023     //�豸���Ƴ�
#define  SAR_PIN_INCORRECT                0x0A000024     //PIN����ȷ
#define  SAR_PIN_LOCKED                   0x0A000025     //PIN������
#define  SAR_PIN_INVALID                  0x0A000026     //PIN��Ч
#define  SAR_PIN_LEN_RANGE                0x0A000027     //PIN���ȴ���
#define  SAR_USER_ALREADY_LOGGED_IN       0x0A000028     //�û��Ѿ���¼
#define  SAR_USER_PIN_NOT_INITIALIZED     0x0A000029     //û�г�ʼ���û�����
#define  SAR_USER_TYPE_INVALID            0x0A00002A     //PIN���ʹ���
#define  SAR_APPLICATION_NAME_INVALID     0x0A00002B     //Ӧ��������Ч
#define  SAR_APPLICATION_EXISTS           0x0A00002C     //Ӧ���Ѿ�����
#define  SAR_USER_NOT_LOGGED_IN           0x0A00002D     //�û�û�е�¼
#define  SAR_APPLICATION_NOT_EXISTS       0x0A00002E     //Ӧ�ò�����
#define  SAR_FILE_ALREADY_EXIST           0x0A00002F     //�ļ��Ѿ�����
#define  SAR_NO_ROOM                      0x0A000030     //�ռ䲻��
#define  SAR_FILE_NOT_EXIST               0x0A000031     //�ļ�������
#define  SAR_REACH_MAX_CONTAINER_COUNT    0x0A000032     //�Ѵﵽ���ɹ���������
#define  SAR_NOCREATEFILE_RIGHT			  0x0A000033	 //û�д����ļ���Ȩ��

//�Զ��������
#define  SAR_CONTAINER_NOT_EXISTS         0x0A000101     //����������

///������������
//typedef signed char INT8;
//typedef signed short INT16;
//typedef signed int  INT32;
//typedef unsigned char UINT8;
//typedef unsigned short UINT16;
//typedef unsigned int  UINT32;
//typedef int BOOL;
//typedef UINT8 BYTE;
//typedef UINT8 CHAR;
//typedef INT16 SHORT;
//typedef UINT16 USHORT;
#if __APPLE__

#else
typedef INT32 LONG;
#endif
typedef UINT32 ULONG;
//typedef UINT32 UINT;
//typedef UINT16 WORD;
//typedef UINT32 DWORD;
typedef CHAR* LPSTR;
typedef void* HANDLE;
typedef HANDLE DEVHANDLE;
typedef HANDLE HAPPLICATION;
typedef HANDLE HCONTAINER;

///��������
#ifdef WIN32
#define DEVAPI _stdcall
#else
#define DEVAPI
#endif
//#define TRUE    0x00000001
//#define FALSE   0x00000000
#define ADMIN_TYPE  0     //����ԱPIN����
#define USER_TYPE   1     //�û�PIN����

///�㷨��ʶ
//���������㷨��ʶ
#define SGD_SM1_ECB    0x00000101  //SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC    0x00000102  //SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB    0x00000104  //SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB    0x00000108  //SM1�㷨0FB����ģʽ
#define SGD_SM1_MAC    0x00000110  //SM1�㷨MAC����
#define SGD_SSF33_ECB  0x00000201  //SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC  0x00000202  //SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB  0x00000204  //SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB  0x00000208  //SSF33�㷨0FB����ģʽ
#define SGD_SSF33_MAC  0x00000210  //SSF33�㷨MAC����
#define SGD_SM4_ECB    0x00000401  //SM4�㷨ECB����ģʽ
#define SGD_SM4_CBC    0x00000402  //SM4�㷨CBC����ģʽ
#define SGD_SM4_CFB    0x00000404  //SM4�㷨CFB����ģʽ
#define SGD_SM4_OFB    0x00000408  //SM4�㷨0FB����ģʽ
#define SGD_SM4_MAC    0x00000410  //SM4�㷨MAC����
//��Ӧ�ö���������ֵΪDES
//#define SGD_ZUC_EEA3   0x00000801  //ZUC���֮�������㷨128-EEA3�㷨
//#define SGD_ZUC_EIA3   0x00000802  //ZUC���֮�������㷨128-EIA3�㷨
#define SGD_DES_ECB    0x00000801  //DES�㷨ECB����ģʽ
#define SGD_DES_CBC    0x00000802  //DES�㷨CBC����ģʽ
#define SGD_DES_MAC    0x00000810  //DES�㷨MAC����

#define SGD_3DES_ECB   0x00001001  //3DES�㷨ECB����ģʽ
#define SGD_3DES_CBC   0x00001002  //3DES�㷨CBC����ģʽ
#define SGD_3DES_MAC   0x00001010  //3DES�㷨MAC����

//��չ�������㷨��ʶ
//#define SGD_3DES_ECB   0x80000101  //3DES-128�㷨ECB����ģʽ
//#define SGD_3DES_CBC   0x80000102  //3DES-128�㷨CBC����ģʽ



#define SGD_3DES24_ECB 0x80000201  //3DES-192�㷨ECB����ģʽ
#define SGD_3DES24_CBC 0x80000202  //3DES-192�㷨CBC����ģʽ
#define SGD_AES_ECB    0x80000401  //AES-128�㷨ECB����ģʽ
#define SGD_AES_CBC    0x80000402  //AES-128�㷨CBC����ģʽ

//�ǶԳ������㷨��ʶ
#define SGD_RSA        0x00010000  //RSA�㷨
#define SGD_SM2        0x00020100  //SM2��Բ���������㷨
#define SGD_SM2_1      0x00020200  //SM2��Բ����ǩ���㷨
#define SGD_SM2_2      0x00020400  //SM2��Բ������Կ����Э��
#define SGD_SM2_3      0x00020800  //SM2��Բ���߼����㷨
//�����Ӵ��㷨��ʶ
#define SGD_SM3        0x00000001  //SM3�Ӵ��㷨
#define SGD_SHA1       0x00000002  //SHA_1�Ӵ��㷨
#define SGD_SHA256     0x00000004  //SHA_256�Ӵ��㷨
//ǩ���㷨��ʶ
#define SGD_SM3_RSA    0x00010001  //����SM3�㷨��RSA�㷨��ǩ��
#define SGD_SHA1_RSA   0x00010002  //����SHA_1�㷨��RSA�㷨��ǩ��
#define SGD_SHA256_RSA 0x00010004  //����SHA_256�㷨��RSA�㷨��ǩ��
#define SGD_SM3_SM2    0x00020201  //����SM3�㷨��SM2�㷨��ǩ��

#pragma pack(1)


static BYTE SHA1_HEAD[15] = {0x30, 0x21, 0x30, 0x09, 0x06, 0x05, 0x2b, 0x0e, 0x03, 0x02, 0x1a, 0x05, 0x00, 0x04, 0x14};
static BYTE SHA256_HEAD[19] = {0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20};
static BYTE SM3_HEAD[18] = {0x30, 0x30, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x83, 0x11, 0x05, 0x00, 0x04, 0x20};

///������������
//�汾
typedef struct Struct_Version{
	BYTE major;
	BYTE minor;
}VERSION;
//�豸��Ϣ
typedef struct Struct_DEVINFO{
	VERSION     Version;             //���ݽṹ�汾��,���ṹ�汾��1.0
	CHAR        Manufacturer[64];    //�豸������Ϣ,�� '\0'������ASCII�ַ���
	CHAR        Issuer[64];          //���г�����Ϣ,�� '\0'������ASCII�ַ���
	CHAR        Label[32];           //�豸��ǩ,�� '\0'������ASCII�ַ���
	CHAR        SerialNumber[32];    //���к�,�� '\0'������ASCII�ַ���
	VERSION     HWVerison;           //�豸Ӳ���汾
	VERSION     FirmwareVersion;     //�豸����̼��汾
	ULONG       AlgSymCap;           //���������㷨��ʶ
	ULONG       AlgAsymCap;          //�ǶԳ������㷨��ʶ
	ULONG       AlgHashCap;          //�����Ӵ��㷨��ʶ
	ULONG       DevAuthAlgId;        //�豸��֤ʱʹ�õķ��������㷨��ʶ
	ULONG       TotalSpace;          //�豸�ܿռ��С
	ULONG       FreeSpace;           //�û����ÿռ��С
	ULONG       MaxECCBufferSize;    //�ܹ������ECC�������ݴ�С
	ULONG       MaxBufferSize;       //�ܹ�����ķ���������Ӵ���������ݴ�С
	BYTE        Reserved[64];        //������չ
}DEVINFO,*PDEVINFO;
#define SKF_DEVINFO
 //RSA��Կ���ݽṹ
#define MAX_RSA_MODULUS_LEN 256 //RSA���֧��2048 λ
#define MAX_RSA_EXPONENT_LEN 4
typedef struct Struct_RSAPUBLICKEYBLOB{ 
	ULONG AlgID;                               //�㷨��ʶ��
 	ULONG BitLen;                              //ģ����ʵ��λ����,������8�ı���
 	BYTE Modulus[MAX_RSA_MODULUS_LEN];         //ģ�� n = p * q ,ʵ�ʳ���ΪBitLen/8�ֽ�
 	BYTE PublicExponent[MAX_RSA_EXPONENT_LEN]; //������Կ e һ��Ϊ 00010001
}RSAPUBLICKEYBLOB, *PRSAPUBLICKEYBLOB; 
//RSA˽Կ���ݽṹ
typedef struct Struct_RSAPRIVATEKEYBLOB{ 
 	ULONG AlgID;                              //�㷨��ʶ�� 
 	ULONG BitLen;                             //ģ����ʵ��λ����,������8�ı���
 	BYTE Modulus[MAX_RSA_MODULUS_LEN];        //ģ�� n = p * q,ʵ�ʳ���Ϊ BitLen/8�ֽ�
 	BYTE PublicExponent[MAX_RSA_EXPONENT_LEN];//������Կe,һ��Ϊ010001 
 	BYTE PrivateExponent[MAX_RSA_MODULUS_LEN];//˽����Կd,ʵ�ʳ���ΪBitLen/8�ֽ�
 	BYTE Prime1[MAX_RSA_MODULUS_LEN/2];       //���� p,ʵ�ʳ���ΪBitLen/16�ֽ� 
 	BYTE Prime2[MAX_RSA_MODULUS_LEN/2];       //���� q,ʵ�ʳ���ΪBitLen/16�ֽ�
 	BYTE Prime1Exponent[MAX_RSA_MODULUS_LEN/2];//d mod (p-1)��ֵ,ʵ�ʳ���ΪBitLen/16�ֽ� 
	BYTE Prime2Exponent[MAX_RSA_MODULUS_LEN/2];//d mod (q -1)��ֵ,ʵ�ʳ���ΪBitLen/16�ֽ� 
	BYTE Coefficient[MAX_RSA_MODULUS_LEN/2];   //qģp�ĳ˷���Ԫ,ʵ�ʳ���ΪBitLen/16�ֽ�
}RSAPRIVATEKEYBLOB, *PRSAPRIVATEKEYBLOB; 
//ECC��Կ���ݽṹ
#define ECC_MAX_XCOORDINATE_BITS_LEN  512
#define ECC_MAX_YCOORDINATE_BITS_LEN  512
typedef struct Struct_ECCPUBLICKEYBLOB{
	ULONG BitLen;                                  //ģ����ʵ��λ����
	BYTE XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];//������X������ , Լ����SM2���ݽṹ��64�ֽ�,��Чλ��32�ֽ�
	BYTE YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];//������Y������
}ECCPUBLICKEYBLOB,*PECCPUBLICKEYBLOB;
//ECC˽Կ���ݽṹ
#define ECC_MAX_MODULUS_BITS_LEN 512
typedef struct Struct_ECCPRIVATEKEYBLOB{
	ULONG BitLen;                               //ģ����ʵ��λ����
	BYTE PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];  //˽����Կ
}ECCPRIVATEKEYBLOB,*PECCPRIVATEKEYBLOB;
//ECC�������ݽṹ
typedef struct Struct_ECCCIPHERBLOB{
	BYTE XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];//��y�����Բ�����ϵĵ�(x,y)
	BYTE YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];//
	BYTE HASH[32];                                   //���ĵ��Ӵ�ֵ
	ULONG CipherLen;                                 //�������ݳ���
	//BYTE Cipher[1];                                  //��������,ʵ�ʳ���ΪCipherLen
	BYTE *Cipher;                                  //��������,ʵ�ʳ���ΪCipherLen
}ECCCIPHERBLOB,*PECCCIPHERBLOB;
//ECCǩ�����ݽṹ
typedef struct Struct_ECCSIGNATUREBLOB{
	BYTE r[ECC_MAX_XCOORDINATE_BITS_LEN/8];       //ǩ�������r����
	BYTE s[ECC_MAX_XCOORDINATE_BITS_LEN/8];       //ǩ�������s����
}ECCSIGNATUREBLOB,*PECCSIGNATUREBLOB;
//�����������
#define MAX_IV_LEN 32
typedef struct Struct_BLOCKCIPHERPARAM{
	BYTE IV[MAX_IV_LEN];   //��ʼ����
	ULONG IVLen;           //��ʼ�������ȣ����ֽڼ��㣩
	ULONG PaddingType;     //��䷽����0��ʾ����䣬1��ʾ����PKCS#5��ʽ���
	ULONG FeedBitLen;      //����ֵ��λ���ȣ���λ���㣩
}BLOCKCIPHERPARAM,*PBLOCKCIPHERPARAM;
//ECC������Կ�Ա����ṹ
typedef struct Struct_ENVELOPEDKEYBLOB{
	ULONG Version;                    //��ǰ�汾Ϊ1
	ULONG ulSymmAlgID;                //�Գ��㷨��ʶ���޶�ECBģʽ
	ULONG ulBits;                     //������Կ�Ե���Կλ����
	BYTE cbEncryptedPriKey[64];       //������Կ��˽Կ������
	ECCPUBLICKEYBLOB PubKey;          //������Կ�ԵĹ�Կ
	ECCCIPHERBLOB ECCCipherBlob;      //�ñ�����Կ���ܵĶԳ���Կ����
}ENVELOPEDKEYBLOB,*PENVELOPEDKEYBLOB;
//�ļ�����
typedef struct Struct_FILEATTRIBUTE{
	CHAR   FileName[32];
	ULONG  FileSize;
	ULONG  ReadRights;
	ULONG  WriteRights;
}FILEATTRIBUTE,*PFILEATTRIBUTE;	
#pragma pack()

//Ȩ������
#define SECURE_NEVER_ACCOUNT  0x00000000   //������
#define SECURE_ADM_ACCOUNT    0x00000001   //����ԱȨ��
#define SECURE_USER_ACCOUNT   0x00000010   //�û�Ȩ��
#define SECURE_ANYONE_ACCOUNT 0x000000ff   //�κ���
//�豸״̬
#define DEV_ABSENT_STATE      0x00000000   //�豸������
#define DEV_PRESENT_STATE     0x00000001   //�豸����
#define DEV_UNKNOW_STATE      0x00000002   //�豸״̬δ֪


//-------------------------�豸����ϵ�к���--------------------------------------
/**
* @brief �ȴ��豸����¼�
* @note  �����������ú����ȴ��豸������߰γ��¼���szDevName ���ط����¼����豸���ơ�
* 
* @param[OUT]     szDevName       �����¼����豸���ơ�  
* @param[IN,OUT]  pulDevNameLen   ����/���������������ʱ��ʾ���������ȣ����ʱ��ʾ�豸���Ƶ���Ч����,���Ȱ����ַ�����������
* @param[OUT]     pulEvent        �¼����͡�1 ��ʾ���룬2 ��ʾ�γ���
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_WaitForDevEvent(LPSTR szDevName,ULONG *pulDevNameLen, ULONG *pulEvent);
/**
* @brief ȡ���ȴ��豸����¼�
* @note  �����������ú���ȡ���ȴ��豸������߰γ��¼���
* 
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_CancelWaitForDevEvent(void);
/**
* @brief ö���豸
* @note  ������������õ�ǰϵͳ�е��豸�б�
* 
* @param[IN]      bPresent     ΪTRUE��ʾȡ��ǰ�豸״̬Ϊ���ڵ��豸�б�ΪFALSE��ʾȡ��ǰ����֧�ֵ��豸�б�  
* @param[OUT]     szNameList   �豸�б����ơ��������ΪNULL������pulSize��������Ҫ�Ŀռ��С��ÿ���豸�������Ե���'\0'��������˫'\0'��ʾ�б������
* @param[IN,OUT]  pulSize      ����ʱ��ʾ�豸�����б�Ļ���������,���ʱ��ʾszNameList��ռ�õĿռ��С��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EnumDev(BOOL bPresent,LPSTR szNameList,ULONG * pulSize);
/**
* @brief �����豸
* @note  ����������ͨ���豸�������豸�������豸�ľ����
*        
* @param[IN]      szName      �豸���ơ�
* @param[OUT]     phDev       �����豸���������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ConnectDev(LPSTR szName,DEVHANDLE * phDdev);
/**
* @brief �Ͽ�����
* @note  �����������Ͽ�һ���Ѿ����ӵ��豸�����ͷž����
*        
* @param[IN]      hDev       �����豸ʱ���ص��豸�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
* 
* @remark ��ע��������豸�ѱ�����������Ӧ���Ƚ������豸���Ͽ����Ӳ�������Ӱ���豸��Ȩ��״̬��
*/
ULONG DEVAPI SKF_DisConnectDev(DEVHANDLE hDev);
/**
* @brief ��ȡ�豸״̬
* @note  ������������ȡ�豸�Ƿ���ڵ�״̬��
*        
* @param[IN]      szDevName      �豸���ơ� 
* @param[OUT]     pulDevState    �����豸״̬��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GetDevState(LPSTR szDevName,ULONG * pulDevState);
/**
* @brief �����豸��ǩ
* @note  ���������������豸��ǩ��
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����   
* @param[IN]      szLabel     �豸��ǩ�ַ��������ַ���ӦС�� 32 �ֽڡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_SetLabel(DEVHANDLE hDev, LPSTR szLabel);
/**
* @brief ��ȡ�豸��Ϣ
* @note  ������������ȡ�豸��һЩ������Ϣ�������豸��ǩ��������Ϣ��֧�ֵ��㷨�ȡ�
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����   
* @param[OUT]     pDevInfo    ���ص��豸��Ϣ��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GetDevInfo(DEVHANDLE hDev,DEVINFO * pDevInfo);
/**
* @brief �����豸
* @note  ��������������豸�Ķ�ռʹ��Ȩ��
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����   
* @param[IN]      ulTimeOut    ��ʱʱ�䣬��λΪ���롣���Ϊ 0xFFFFFFFF ��ʾ���޵ȴ���
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_LockDev(DEVHANDLE hDev, ULONG ulTimeOut);
/**
* @brief �����豸
* @note  �����������ͷŶ��豸�Ķ�ռʹ��Ȩ��
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����   
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_UnlockDev(DEVHANDLE hDev);
/**
* @brief �豸�����
* @note  ������ֱ�ӷ��͸��豸�������ؽ����
*        
* @param[IN]      hDdev         �豸�����
* @param[IN]      pbCommand     �豸���
* @param[IN]      ulCommandLen  ����ȡ�
* @param[OUT]     pbData        ���ؽ�����ݡ�
* @param[IN,OUT]  pulDataLen    ����ʱ��ʾ������ݻ��������ȣ����ʱ��ʾ�������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_Transmit(DEVHANDLE hDev,BYTE * pbCommand, ULONG ulCommandLen,BYTE * pbData, ULONG * pulDataLen);

///���ʿ���ϵ�к���
/**
* @brief �޸��豸��֤��Կ
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����
* @param[IN]      pbKeyValue  ��Կֵ�� 
* @param[IN]      ulKeyLen    ��Կ���ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ���豸��֤�ɹ������ʹ�á�
*/
ULONG DEVAPI SKF_ChangeDevAuthKey(DEVHANDLE hDev,BYTE * pbKeyValue,ULONG ulKeyLen);
/**
* @brief �豸��֤
* @note  ��֤���̣�����֤����ȡ8�ֽ������RND,���0��16�ֽڵõ�D0,���ܵõ����D1,�豸�յ�D1��֤�Ƿ���ȷ��
*        
* @param[IN]      hDdev       �����豸ʱ���ص��豸�����
* @param[IN]      pbAuthData  ��֤���ݡ�
* @param[IN]      ulLen       ��֤���ݳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_DevAuth(DEVHANDLE hDev,BYTE * pbAuthData,ULONG ulLen);
/**
* @brief �޸�PIN
* @note  �������������øú��������޸�Administrator PIN��User PIN��
*        ���ԭPIN���������֤ʧ��,�ú����᷵����ӦPIN��ʣ�����Դ�������ʣ�����Ϊ0ʱ����ʾPIN�Ѿ�������
*        
* @param[IN]      hApplication    Ӧ�þ����
* @param[IN]      ulPINType       PIN����, ��ΪADMIN_TYPE��USER_TYPE��
* @param[IN]      szOldPin        ԭPINֵ��
* @param[IN]      szNewPin        ԭPINֵ��
* @param[OUT]     pulRetryCount   ���������Դ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ChangePIN(HAPPLICATION hApplication,ULONG ulPINType,LPSTR szOldPin,LPSTR szNewPin,ULONG * pulRetryCount);
/**
* @brief ��ȡPIN��Ϣ
* @note  ��������������������Դ�������ǰʣ�����Դ������Լ���ǰPIN�Ƿ�Ϊ����Ĭ��PIN�롣
*        
* @param[IN]      hApplication         Ӧ�þ����
* @param[IN]      ulPINType            PIN����, ��ΪADMIN_TYPE��USER_TYPE�� 
* @param[OUT]     pulMaxRetryCount     ������Դ�����
* @param[OUT]     pulRemainRetryCount  ��ǰʣ�����Դ�������Ϊ0ʱ��ʾ��������
* @param[OUT]     pbDefaultPin         �Ƿ�Ϊ����Ĭ��PIN�롣
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GetPINInfo(HAPPLICATION hApplication,ULONG ulPINType,ULONG * pulMaxRetryCount,ULONG * pulRemainRetryCount,BOOL * pbDefaultPin);
/**
* @brief У��PIN
* @note  ����������У��ɹ��󣬻�����Ӧ��Ȩ�ޣ����PIN����󣬻᷵��PIN�����Դ�����������Ϊ0ʱ��ʾPIN����������
*        
* @param[IN]      hApplication     Ӧ�þ����
* @param[IN]      ulPINType       PIN����, ��ΪADMIN_TYPE��USER_TYPE��
* @param[IN]      pulRetryCount   PIN�롣
* @param[OUT]     pulRetryCount   ���������Դ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_VerifyPIN(HAPPLICATION hApplication,ULONG ulPINType,LPSTR szPIN, ULONG * pulRetryCount);
/**
* @brief ����PIN
* @note  �������������û��� PIN ��������ͨ�����øú����������û� PIN �롣 �������û� PIN �뱻���ó���ֵ���û� PIN ������Դ���Ҳ�ָ���ԭֵ��
*        
* @param[IN]      hApplication    Ӧ�þ����
* @param[IN]      szAdminPIN      ����Ա PIN �롣
* @param[IN]      szNewUserPIN    �µ��û� PIN �롣
* @param[OUT]     pulRetryCount   ����Ա PIN �����ʱ������ʣ�����Դ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark  Ȩ��Ҫ����֤�����Ա PIN ���ܹ������û� PIN �룬�������� Administrator PIN����ȷ�����Ѿ������������ʧ�ܣ������� Administrator PIN �����Դ����� 
*/
ULONG DEVAPI SKF_UnblockPIN (HAPPLICATION hApplication, LPSTR szAdminPIN, LPSTR szNewUserPIN, ULONG *pulRetryCount);
/**
* @brief ���Ӧ�ð�ȫ״̬
*         
* @param[IN]      hApplication     Ӧ�þ����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ClearSecureState (HAPPLICATION hApplication);

///----------------------------Ӧ�ù���ϵ�к���-------------------------------
/**
* @brief ����Ӧ��
*
* @param[IN]      hDdev                �����豸ʱ���ص��豸�����
* @param[IN]      szAppName            Ӧ�����ơ�
* @param[IN]      szAdminPin           ����ԱPIN��
* @param[IN]      dwAdminPinRetryCount ����ԱPIN������Դ�����
* @param[IN]      szUserPin            �û�PIN��
* @param[IN]      dwUserPinRetryCount  �û�PIN������Դ�����
* @param[IN]      dwCreateFileRights   �ڸ�Ӧ���´����ļ���������Ȩ�ޡ�
* @param[OUT]     phApplication        Ӧ�õľ����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark  Ȩ��Ҫ����Ҫ�豸Ȩ��
*/
ULONG DEVAPI SKF_CreateApplication(DEVHANDLE hDev,LPSTR szAppName,LPSTR szAdminPin,DWORD dwAdminPinRetryCount,LPSTR szUserPin,DWORD dwUserPinRetryCount,DWORD dwCreateFileRights,HAPPLICATION * phApplication);
/**
* @brief ö��Ӧ��
*        
* @param[IN]      hDdev         �����豸ʱ���ص��豸����� 
* @param[OUT]     szAppName     ����Ӧ�������б�,�������Ϊ�գ�����pulSize���������ڴ��С��ÿ��Ӧ���Ե���'\0'����,��˫'\0'��ʾ�б������
* @param[IN,OUT]  pulSize       ����ʱ��ʾ���������ȣ����ʱ����ռ�ÿռ��С��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EnumApplication(DEVHANDLE hDev,LPSTR szAppName,ULONG * pulSize);
/**
* @brief ɾ��Ӧ�� 
*        
* @param[IN]      hDdev         �����豸ʱ���ص��豸����� 
* @param[IN]      szAppName     Ӧ�����ơ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�豸Ȩ��
*/
ULONG DEVAPI SKF_DeleteApplication(DEVHANDLE hDev,LPSTR szAppName);
/**
* @brief ��Ӧ��
*        
* @param[IN]      hDdev         �����豸ʱ���ص��豸����� 
* @param[IN]      szAppName     Ӧ�����ơ�
* @param[OUT]     phApplication Ӧ�õľ����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_OpenApplication(DEVHANDLE hDev,LPSTR szAppName,HAPPLICATION * phApplication);
/**
* @brief �ر�Ӧ��
*        
* @param[IN]     hApplication    Ӧ�þ���� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ��ע���˺�����Ӱ��Ӧ�ð�ȫ״̬��
*/
ULONG DEVAPI SKF_CloseApplication(HAPPLICATION hApplication);

///-----------------------------�ļ�����ϵ�к���---------------------------------
/**
* @brief �����ļ�
* @note  ���������������ļ�ʱҪָ���ļ������ơ���С���Լ���дȨ�ޡ�
*        
* @param[IN]     hApplication    Ӧ�þ���� 
* @param[IN]     szFileName      �ļ����ƣ����Ȳ��ô���32���ֽڡ� 
* @param[IN]     ulFileSize      �ļ���С��
* @param[IN]     ulReadRights    �ļ���Ȩ�ޡ�
* @param[IN]     ulWriteRights   �ļ�дȨ�ޡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ�󣺴����ļ���ҪӦ��ָ���Ĵ����ļ�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_CreateFile(HAPPLICATION hApplication,LPSTR szFileName,ULONG ulFileSize,ULONG ulReadRights,ULONG ulWriteRights);
/**
* @brief ɾ���ļ�
* @note  �����������ļ�ɾ�����ļ���д���������Ϣ����ʧ���ļ����豸��ռ�õĿռ佫���ͷš�
*        
* @param[IN]     hApplication    Ҫɾ�����ļ����ڵ�Ӧ�þ���� 
* @param[IN]     szFileName      Ҫɾ�����ļ������ơ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ��ɾ��һ���ļ�Ӧ���жԸ��ļ��Ĵ���Ȩ�ޡ�
*/
ULONG DEVAPI SKF_DeleteFile(HAPPLICATION hApplication,LPSTR szFileName);
/**
* @brief ö���ļ�
*        
* @param[IN]     hApplication    Ӧ�þ����
* @param[OUT]    szFileList      �����ļ������б�,�������Ϊ�գ�����pulSize���������ڴ��С��ÿ���ļ������Ե���'\0'����,��˫'\0'��ʾ�б������
* @param[IN,OUT] pulSize         ����ʱ��ʾ���������ȣ����ʱ����ռ�ÿռ��С��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EnumFiles(HAPPLICATION hApplication,LPSTR szFileList,ULONG * pulSize);
/**
* @brief ��ȡ�ļ�����
*        
* @param[IN]     hApplication    Ӧ�þ���� 
* @param[IN]     szFileName      �ļ����ơ�
* @param[OUT]    pFileInfo       �ļ���Ϣ�� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GetFileInfo(HAPPLICATION hApplication,LPSTR szFileName,FILEATTRIBUTE * pFileInfo);
/**
* @brief ���ļ�
*        
* @param[IN]     hApplication    Ӧ�þ���� 
* @param[IN]     szFileName      �ļ����ơ�
* @param[IN]     ulOfffset       �ļ���ȡƫ��λ�á�
* @param[IN]     ulSize          Ҫ��ȡ�ļ��ĳ��ȡ�
* @param[OUT]    pbOutData       �������ݵĻ�������
* @param[IN,OUT] pulOutLen       ����ʱ��ʾ���������ȣ����ʱ��ʾʵ�ʶ�ȡ���ص����ݴ�С��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����߱����ļ��Ķ�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_ReadFile(HAPPLICATION hApplication,LPSTR szFileName,ULONG ulOfffset,ULONG ulSize,BYTE * pbOutData,ULONG * pulOutLen);
/**
* @brief д�ļ�      
*        
* @param[IN]     hApplication    Ӧ�þ���� 
* @param[IN]     szFileName      �ļ����ơ�
* @param[IN]     ulOfffset       д���ļ���ƫ������
* @param[IN]     pbData          д�����ݵĻ�������
* @param[IN]     ulSize          д�����ݵĴ�С��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����߱����ļ��Ķ�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_WriteFile(HAPPLICATION hApplication,LPSTR szFileName,ULONG ulOfffset,BYTE * pbData,ULONG ulSize);

///-----------------------------��������ϵ�к���----------------------------------
/**
* @brief ��������
* @note  ������������Ӧ���½����ƶ����Ƶ��������������������    
*     
* @param[IN]     hApplication    Ӧ�þ����
* @param[IN]     szContainerName ��������,ASCII�ַ�������󳤶Ȳ�����64�ֽڡ�
* @param[OUT]    pbContainer     ���������������������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ��
*/
ULONG DEVAPI SKF_CreateContainer(HAPPLICATION hApplication,LPSTR szContainerName,HCONTAINER * pbContainer);
/**
* @brief ɾ������    
*        
* @param[IN]     hApplication    Ӧ�þ����
* @param[IN]     szContainerName ָ��ɾ�����������ơ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ��
*/
ULONG DEVAPI SKF_DeleteContainer(HAPPLICATION hApplication,LPSTR szContainerName);

/*
* @brief ö������
* @note  ����������ö��Ӧ���µ������������������������б�
*        
* @param[IN]     hApplication    Ӧ�þ����
* @param[OUT]    szContainerName ָ�����������б�����������˲���Ϊ NULL ʱ��pulSize��ʾ������������Ҫ�������ĳ��ȣ�����˲�����Ϊ NULL ʱ���������������б�ÿ���������Ե�����\0��Ϊ�������б���˫��\0��������
* @param[IN,OUT] pulSize         ����ǰ��ʾ szContainerName �������ĳ��ȣ��������������б�ĳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EnumContainer (HAPPLICATION hApplication,LPSTR szContainerName,ULONG *pulSize);
/**
* @brief ������
*        
* @param[IN]     hApplication    Ӧ�þ����
* @param[IN]     szContainerName �������ơ�
* @param[OUT]    pbContainer     ���ش򿪵ĵ����������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_OpenContainer(HAPPLICATION hApplication,LPSTR szContainerName,HCONTAINER * pbContainer);
/**
* @brief �ر�����
*        
* @param[IN]      hContainer     ���������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_CloseContainer(HCONTAINER hContainer);
/**
* @brief �����������
*        
* @param[IN]      hContainer       ���������
* @param[OUT]     pulContainerType �������ͣ�ָ��ָ���ֵΪ0��ʾδ������δ�������ͻ��߿�������Ϊ1��ʾRSA������Ϊ2��ʾSM2���� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GetContainerType(HCONTAINER hContainer,ULONG * pulContainerType);
/**
* @brief ��������֤��
*        
* @param[IN]      hContainer       ���������
* @param[IN]      bSignFlag        TRUE��ʾǩ��֤�飬FALSE��ʾ����֤�顣
* @param[IN]      pbCert           ָ��֤�����ݻ�������
* @param[IN]      ulCertLen        ֤�鳤�ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ImportCertificate(HCONTAINER hContainer,BOOL bSignFlag,BYTE * pbCert,ULONG ulCertLen);
/**
* @brief ��������֤��
*        
* @param[IN]      hContainer       ���������
* @param[IN]      bSignFlag        TRUE��ʾǩ��֤�飬FALSE��ʾ����֤�顣
* @param[IN]      pbCert           ָ��֤�����ݻ�����������˲���ΪNULLʱ��pulCertLen��ʾ�����������軺�������ȣ����򷵻�֤�����ݡ�
* @param[IN/OUT]  pulCertLen       ����ʱ��ʾpbCert�������ĳ��ȣ����ʱ��ʾ֤�����ݵĳ��ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExportCertificate(HCONTAINER hContainer,BOOL bSignFlag,BYTE * pbCert,ULONG * pulCertLen);

///------------------------------�������ϵ�к���-----------------------------------
/**
* @brief ���������
* @note  ����ָ�����ȵ������ 
* 
* @param[IN]      hDev        �豸�����
* @param[OUT]     pbRandom    ���ص��������
* @param[IN]      ulRandomLen ��������ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_GenRandom(DEVHANDLE hDev,BYTE * pbRandom,ULONG ulRandomLen);
/**
* @brief �����ⲿRSA��Կ��
* @note  ���豸����RSA��Կ�Բ����������
*        
* @param[IN]      hDev       �豸�����
* @param[IN]      ulBitsLen  ��Կģ����
* @param[OUT]	  pBlob      ���ص�˽Կ���ݽṹ��    
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ���ɵ�˽Կֻ����������ӿ��ڲ��������ͼ��㡣 
*/
ULONG DEVAPI SKF_GenExtRSAKey(DEVHANDLE hDev, ULONG  ulBitsLen,RSAPRIVATEKEYBLOB * pBlob);
/**
* @brief ����RSAǩ����Կ��
* @note  ����RSAǩ����Կ�Բ����ǩ����Կ��
*        
* @param[IN]      hContainer       ���������
* @param[IN]      ulBitsLen        ��Կģ����
* @param[OUT]	  pBlob            ���ص�RSA��Կ���ݽṹ      
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����߱��û�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_GenRSAKeyPair(HCONTAINER hContainer, ULONG ulBitsLen, RSAPUBLICKEYBLOB * pBlob);
/**
* @brief ����RSA������Կ��
* @note  ����RSA���ܹ�˽Կ��
*        
* @param[IN]      hContainer         ���������
* @param[IN]      ulSymAlgId         �Գ��㷨��Կ��ʶ��
* @param[IN]      pbWrappedKey       ʹ�ø�������ǩ����Կ�����ĶԳ��㷨��Կ��
* @param[IN]      ulWrappedKeyLen    �����ĶԳ��㷨��Կ����
* @param[IN]      pbEncryptedData    �Գ��㷨��Կ������ RSA ����˽Կ��˽Կ�ĸ�ʽ��ѭ PKCS#1 v2.1: RSA Cryptography Standard �е�˽Կ��ʽ���塣��
* @param[IN]      ulEncryptedDataLen �Գ��㷨��Կ������ RSA ���ܹ�˽Կ�Գ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����߱��û�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_ImportRSAKeyPair(HCONTAINER hContainer, ULONG ulSymAlgId, BYTE * pbWrappedKey, ULONG ulWrappedKeyLen,BYTE * pbEncryptedData, ULONG ulEncryptedDataLen);
/**
* @brief RSAǩ��
* @note  ʹ��hContainerָ��������ǩ��˽Կ����ָ������ pbData ��������ǩ����ǩ����Ľ����ŵ� pbSignature ������������ pulSignLen Ϊǩ���ĳ��ȡ�
*        
* @param[IN]      hContainer    ����ǩ����˽Կ�������������
* @param[IN]      pbData        ��ǩ�������ݡ�
* @param[IN]      ulDataLen     ǩ�����ݳ��ȣ�Ӧ������ RSA ��Կģ��-11��
* @param[OUT]     pbSignature   ���ǩ������Ļ�����ָ�룬���ֵΪ NULL������ȡ��ǩ��������ȡ�
* @param[IN,OUT]  pulSignLen    ����Ϊǩ�������������С�����Ϊǩ��������ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����߱��û�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_RSASignData(HCONTAINER hContainer, BYTE * pbData, ULONG ulDataLen, BYTE * pbSignature, ULONG * pulSignLen);
/**
* @brief RSA��ǩ
* @note  ��֤RSAǩ������ pRSAPubKeyBlob �ڵĹ�Կֵ�Դ���ǩ���ݽ�����ǩ�� 
*        
* @param[IN]      hDev            �豸�����
* @param[IN]      pRSAPubKeyBlob  ��Կ���ݽṹ��
* @param[IN]      pbData          ����֤ǩ�������ݡ�
* @param[IN]      ulDataLen       ���ݳ��ȣ�Ӧ�����ڹ�Կģ��-11��
* @param[IN]      pbSignature     ����֤��ǩ��ֵ��
* @param[IN]      ulSignLen       ǩ��ֵ���ȣ�����Ϊ��Կģ����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_RSAVerify(DEVHANDLE hDev, RSAPUBLICKEYBLOB * pRSAPubKeyBlob, BYTE * pbData, ULONG ulDataLen, BYTE * pbSignature, ULONG ulSignLen);
/**
* @brief RSA���ɲ������Ự��Կ
* @note ���ɻỰ��Կ�����ⲿ��Կ��������� 
*        
* @param[IN]      hContainer      ���������
* @param[IN]      ulAlgId         �Ự��Կ�㷨��ʶ��
* @param[IN]      pPubKey         ���ܻỰ��Կ�� RSA ��Կ���ݽṹ��
* @param[OUT]     pbData          �����ļ��ܻỰ��Կ���ģ����� PKCS#1v1.5 Ҫ���װ��
* @param[IN,OUT]  pulDataLen      ���ص������ݳ��ȡ�
* @param[OUT]     phSessionKey    ��������Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_RSAExportSessionKey(HCONTAINER hContainer,ULONG ulAlgId,RSAPUBLICKEYBLOB * pPubKey, BYTE * pbData, ULONG * pulDataLen, HANDLE * phSessionKey);
/**
* @brief RSA������Կ����
* @note ʹ���ⲿ����� RSA ��Կ��������������Կ���㲢��������
*        
* @param[IN]        hDev            �豸�����
* @param[IN]        pRSAPubKeyBlob  RSA ��Կ���ݽṹ��
* @param[IN]        pbInput         ָ��������ԭʼ���ݻ�������
* @param[IN]        ulInputLen      ������ԭʼ���ݵĳ��ȣ�����Ϊ��Կģ����
* @param[OUT]       pbOutput        ָ�� RSA ��Կ������������������ò���ΪNULL������ pulOutputLen ������������ʵ�ʳ��ȡ�
* @param[IN,OUT]    pulOutputLen    ����ǰ��ʾ pbOutput �������ĳ��ȣ�����RSA ��Կ��������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtRSAPubKeyOperation(DEVHANDLE hDev, RSAPUBLICKEYBLOB * pRSAPubKeyBlob,BYTE * pbInput, ULONG ulInputLen, BYTE * pbOutput, ULONG * pulOutputLen);
/**
* @brief  RSA����˽Կ����
* @note   ֱ��ʹ���ⲿ����� RSA ˽Կ������������˽Կ���㲢��������
*        
* @param[IN]        hDev            �豸�����
* @param[IN]        pRSAPriKeyBlob  RSA ˽Կ���ݽṹ,��Ҫ��乫Կ��Ϣ��
* @param[IN]        pbInput         ָ����������ݻ�������
* @param[IN]        ulInputLen      ���������ݵĳ��ȣ�����Ϊ��Կģ����
* @param[OUT]       pbOutput        RSA ˽Կ������������ò���Ϊ NULL������pulOutputLen ������������ʵ�ʳ��ȡ�
* @param[IN,OUT]    pulOutputLen    ����ǰ��ʾ pbOutput �������ĳ��ȣ�����RSA ˽Կ��������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtRSAPriKeyOperation(DEVHANDLE  hDev, RSAPRIVATEKEYBLOB *  pRSAPriKeyBlob,BYTE * pbInput,  ULONG  ulInputLen, BYTE * pbOutput, ULONG * pulOutputLen);
/**
* @brief  ����ECCǩ����Կ��
* @note   ����ECCǩ����Կ�Բ����ǩ����Կ   
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      ulAlgId           �㷨��ʶ��ֻ֧��SGD_SM2_1�㷨��
* @param[OUT]     pBlob             ����ECC��Կ���ݽṹ��      
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ��
*/
ULONG DEVAPI SKF_GenECCKeyPair(HCONTAINER hContainer,ULONG ulAlgId,PECCPUBLICKEYBLOB pBlob);
/**
* @brief ����ECC��˽Կ��    
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      pEenvlopedKeyBlob �ܱ����ļ�����Կ�ԡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ��
*/
ULONG DEVAPI SKF_ImportECCKeyPair(HCONTAINER hContainer,PENVELOPEDKEYBLOB pEenvlopedKeyBlob);
/**
* @brief ECCǩ��
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      pbData            ��ǩ�������ݡ�
* @param[IN]      ulDataLen         ��ǩ�������ݳ��ȣ�����С����Կģ����
* @param[OUT]     pSignature		ǩ��ֵ��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ�ޡ�
*        ��������λ��ǩ���ݵ��Ӵ�ֵ,ʹ��SM2�㷨ʱ,����������λ��ǩ�����ݾ���SM2ǩ��Ԥ����Ľ����
*/
ULONG DEVAPI SKF_ECCSignData(HCONTAINER hContainer,BYTE * pbData,ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
/**
* @brief ECC��ǩ
* @note  ��������λ��ǩ���ݵ��Ӵ�ֵ,ʹ��SM2�㷨ʱ,����������λ��ǩ�����ݾ���SM2ǩ��Ԥ����Ľ����
*        
* @param[IN]      hDev            �豸�����
* @param[IN]      pECCPubKeyBlob  ECC��Կ���ݽṹ��
* @param[IN]      pbData          ����֤ǩ�������ݡ�
* @param[IN]      ulDataLen       ���ݳ��ȡ�
* @param[IN]      pSignature      ����֤ǩ��ֵ��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ECCVerify(DEVHANDLE hDev,PECCPUBLICKEYBLOB  pECCPubKeyBlob,BYTE * pbData,ULONG ulDataLen,PECCSIGNATUREBLOB pSignature);
/**
* @brief ECC���ɲ������Ự��Կ
* @note  �������������ɻỰ��Կ�����ⲿ��Կ���ܵ�����
*        
* @param[IN]      hContainer        ���������
* @param[IN]      ulAlgId           �Ự��Կ�㷨��ʶ��
* @param[IN]      pPubKey           �ⲿ����Ĺ�Կ�ṹ��
* @param[OUT]     pData             �Ự��Կ���ġ�
* @param[OUT]     phSessionKey      �Ự��Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ECCExportSessionKey(HCONTAINER hContainer,ULONG ulAlgId,PECCPUBLICKEYBLOB pPubKey,PECCCIPHERBLOB pData,HANDLE * phSessionKey);
/**
* @brief ECC������Կ����
* @note   ��������:ʹ���ⲿ����� ECC ��Կ�������������������㲢��������
*        
* @param[IN]      hDev            �豸�����
* @param[IN]      pECCPubkeyBlob  ECC��Կ���ݽṹ��
* @param[IN]      pbPlainText     �����ܵ��������ݡ�
* @param[IN]      ulPlainTextLen  �����ܵ��������ݳ��ȡ�
* @param[OUT]     pCipherText     �������ݡ�    
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtECCEncrypt(DEVHANDLE hDev,PECCPUBLICKEYBLOB pECCPubkeyBlob,BYTE * pbPlainText,ULONG ulPlainTextLen,PECCCIPHERBLOB pCipherText);
/**
* @brief ECC����˽Կ����
* @note   ��������:ʹ���ⲿ����� ECC ˽Կ�������������������㲢��������
*        
* @param[IN]      hDev            �豸�����
* @param[IN]      pECCPriKeyBlob  ECC ˽Կ���ݽṹ��
* @param[IN]      pCipherText     �����ܵ��������ݡ�
* @param[OUT]     pbPlainText     �����������ݣ�����ò���Ϊ NULL������pulPlainTextLen �����������ݵ�ʵ�ʳ��ȡ�
* @param[IN,OUT]  pulPlainTextLen ����ǰ��ʾpbPlainText �������ĳ��ȣ������������ݵ�ʵ�ʳ��ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtECCDecrypt(DEVHANDLE hDev,  ECCPRIVATEKEYBLOB * pECCPriKeyBlob,PECCCIPHERBLOB pCipherText,BYTE * pbPlainText, ULONG * pulPlainTextLen);
/**
* @brief ECC����˽Կǩ��
* @note   ��������:ʹ���ⲿ����� ECC ˽Կ������������ǩ�����㲢��������
*        
* @param[IN]      hDev            �豸�����
* @param[IN]      pECCPriKeyBlob  ECC ˽Կ���ݽṹ��
* @param[IN]      pbData          ��ǩ�����ݡ� 
* @param[IN]      ulDataLen       ��ǩ�����ݵĳ��ȡ� 
* @param[OUT]     pSignature      ǩ��ֵ��     
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtECCSign(DEVHANDLE hDev, ECCPRIVATEKEYBLOB * pECCPriKeyBlob,BYTE * pbData,ULONG ulDataLen,PECCSIGNATUREBLOB pSignature);
/**
* @brief ECC������Կ��ǩ
* @note   ��������:�ⲿʹ�ô����ECC��Կ��ǩ����֤��  
*
* @param[IN]     hDev           �豸�����
* @param[IN]     pECCPubKeyBlob ECC��Կ���ݽṹ��
* @param[IN]     pbData         ����֤���ݡ�
* @param[IN]     ulDataLen      ����֤���ݵĳ��ȡ� 
* @param[IN]     pSignature     ǩ��ֵ�� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ExtECCVerify(DEVHANDLE hDev, PECCPUBLICKEYBLOB pECCPubKeyBlob,BYTE* pbData, ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
/**
* @brief ECC������ԿЭ�̲��������
* @note  ʹ�� ECC ��ԿЭ���㷨��Ϊ����Ự��Կ������Э�̲�����������ʱ ECC ��Կ�ԵĹ�Կ��Э�̾����   
*
* @param[IN]     hContainer           ���������
* @param[IN]     ulAlgId              �Ự��Կ�㷨��ʶ��
* @param[OUT]    pTempECCPubKeyBlob   ������ʱ ECC ��Կ��
* @param[IN]     pbID                 ���𷽵�ID��
* @param[IN]     ulIDLen              ���� ID �ĳ��ȣ������� 32��
* @param[OUT]    phAgreementHandle    ���ص���ԿЭ�̾����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
* 
* @remark ΪЭ�̻Ự��Կ��Э�̵ķ���Ӧ���ȵ��ñ�����
*/
ULONG DEVAPI SKF_GenerateAgreementDataWithECC(HCONTAINER hContainer, ULONG ulAlgId,ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,BYTE* pbID, ULONG ulIDLen,HANDLE *phAgreementHandle);
/**
* @brief ECC����Э�����ݲ�����Ự��Կ
* @note  ʹ�� ECC ��ԿЭ���㷨������Э�̲���������Ự��Կ�������ʱ ECC ��Կ�Թ�Կ�������ز�������Կ�����    
*
* @param[IN]     hContainer                ���������
* @param[IN]     ulAlgId                   �Ự��Կ�㷨��ʶ��
* @param[IN]     pSponsorECCPubKeyBlob     ���𷽵� ECC ��Կ��
* @param[IN]     pSponsorTempECCPubKeyBlob ���𷽵���ʱ ECC ��Կ��
* @param[OUT]    pTempECCPubKeyBlob        ��Ӧ������ʱ ECC ��Կ��
* @param[IN]     pbID                      ��Ӧ���� ID��
* @param[IN]     ulIDLen                   ��Ӧ�� ID �ĳ��ȣ������� 32��
* @param[IN]     pbSponsorID               ���𷽵� ID��
* @param[IN]     ulSponsorIDLen            ���� ID �ĳ��ȣ������� 32��
* @param[OUT]     phKeyHandle              ���صĶԳ��㷨��Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ����������Ӧ������
*/
ULONG DEVAPI SKF_GenerateAgreementDataAndKeyWithECC(HANDLE hContainer, ULONG ulAlgId,ECCPUBLICKEYBLOB* pSponsorECCPubKeyBlob,ECCPUBLICKEYBLOB* pSponsorTempECCPubKeyBlob,ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,BYTE* pbID, ULONG ulIDLen, BYTE *pbSponsorID, ULONG ulSponsorIDLen,HANDLE *phKeyHandle);
/**
* @brief ECC����Ự��Կ
* @note  ʹ�� ECC ��ԿЭ���㷨��ʹ������Э�̾������Ӧ����Э�̲�������Ự��Կ��ͬʱ���ػỰ��Կ�����    
*
* @param[IN]     hAgreementHandle    ��ԿЭ�̾����
* @param[IN]     pECCPubKeyBlob      �ⲿ�������Ӧ�� ECC ��Կ��
* @param[IN]     pTempECCPubKeyBlob  �ⲿ�������Ӧ����ʱ ECC ��Կ��
* @param[IN]     pbID                ��Ӧ���� ID��
* @param[IN]     ulIDLen             ��Ӧ�� ID �ĳ��ȣ������� 32��
* @param[OUT]     phKeyHandle        ���ص���Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Э�̵ķ��𷽻����Ӧ����Э�̲�������ñ�����������Ự��Կ��
*/
ULONG DEVAPI SKF_GenerateKeyWithECC(HANDLE hAgreementHandle,ECCPUBLICKEYBLOB* pECCPubKeyBlob,ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,BYTE* pbID, ULONG ulIDLen, HANDLE *phKeyHandle);
/**
* @brief ������Կ
* @note  �������������������е�ǩ����Կ����ܹ�Կ
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      bSignFlag         TRUE��ʾ����ǩ����Կ��FALSE��ʾ�������ܹ�Կ��
* @param[OUT]     pbBlob            ָ��RSA��Կ�ṹ����ECC��Կ�ṹ������˲���ΪNULL����pulBlobLen���صĳ���
* @param[IN,OUT]  pulBlobLen        ����ʱ��ʾpbBlob���������ȣ����ʱ��ʾ������Կ�ṹ��С��
*
* @retval SAR_OK:              �ɹ���
* @retval SAR_ BAD_SIGNATURE�� ��֤ʧ�ܡ�
* @retval ������               �����롣
*/
ULONG DEVAPI SKF_ExportPublicKey(HCONTAINER hContainer,BOOL bSignFlag,BYTE * pbBlob,ULONG * pulBlobLen);
/**
* @brief ����Ự��Կ
* @note  ��������������Ự��Կ���ģ�ʹ�������м���˽Կ���ܡ�
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      ulAlgId           �Ự��Կ�㷨��ʶ��
* @param[IN]      pbWrapedData      Ҫ����ĻỰ��Կ���ġ�������ΪECC����ʱ���˲���ΪECCCIPHERBLOB��������,������ΪRSA����ʱ���˲���ΪRSA��Կ���ܺ�����ݡ�
* @param[IN]      ulWrapedLen       �Ự��Կ���ĳ��ȡ�
* @param[OUT]     phKey             ���ػỰ��Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ���û�Ȩ�ޡ�
*/
ULONG DEVAPI SKF_ImportSessionKey(HCONTAINER hContainer,ULONG ulAlgId,BYTE * pbWrapedData,ULONG ulWrapedLen,HANDLE * phKey);
/**
* @brief ���ĵ���Ự����
* @note  �����������������ĶԳ���Կ��������Կ����� 
*        
* @param[IN]      hDev       �豸�����
* @param[IN]      pbKey      ָ��Ự��Կֵ�Ļ�������
* @param[IN]      ulAlgID    �Ự��Կ�㷨��ʶ��
* @param[OUT]     phKey      ���ػỰ��Կ�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_SetSymmKey(DEVHANDLE hDev, BYTE* pbKey, ULONG ulAlgID, HANDLE* phKey);
/**
* @brief ���ܳ�ʼ��
* @note  �����������������ݼ��ܵ��㷨��ز���
*        
* @param[IN]      hKey         ������Կ�����
* @param[IN]      EncryptParam ������Կ�㷨��ز�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EncryptInit(HANDLE hKey,BLOCKCIPHERPARAM EncryptParam);
/**
* @brief �������ݼ���
* @note  ������������һ�������ݵļ��ܲ������ڵ���SKF_Encrypt֮ǰ�����ȵ���SKF_EncryptInit��ʼ����
*        
* @param[IN]      hKey            ������Կ�����
* @param[IN]      pbData          ���������ݡ�
* @param[IN]      ulDataLen       ���������ݳ��ȡ�
* @param[OUT]     pbEncryptedData ���ܺ�����ݻ�����������ΪNULL�����ڻ�ü��ܺ����ݳ��ȡ�
* @param[IN,OUT]  pulEncryptedLen ����ʱ��ʾ���������ȣ����ʱ��ʾ�������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_Encrypt(HANDLE hKey,BYTE * pbData,ULONG ulDataLen,BYTE * pbEncryptedData,ULONG * pulEncryptedLen);
/**
* @brief �������ݼ���
* @note  �����������Զ���������ݽ��м��ܡ��ڵ���SKF_EncryptUpdate֮ǰ�����ȵ���SKF_EncryptInit���ڵ���SKF_EncryptUpdate֮�󣬱������SKF_EncryptFinal��
*        
* @param[IN]      hKey            ������Կ�����
* @param[IN]      pbData          ���������ݡ�
* @param[IN]      ulDataLen       ���������ݳ��ȡ�
* @param[OUT]     pbEncryptedData ���ܺ�����ݻ�����ָ�롣
* @param[OUT]     pulEncryptedLen ���ؼ��ܺ�����ݳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EncryptUpdate(HANDLE hKey,BYTE * pbData,ULONG ulDataLen,BYTE * pbEncryptedData,ULONG * pulEncryptedLen);
/**
* @brief ��������
* @note  �������������������������ݼ��ܣ�����ʣ����ܽ�����ȵ���SKF_EncryptInit��ʼ�����ٵ���SKF_EncryptUpdate�Զ��������ܣ�������SKF_EncryptFinal��������������ݼ��ܡ�
*        
* @param[IN]      hKey            ������Կ�����
* @param[OUT]     pbEncryptedData ���ܽ���Ļ�������
* @param[OUT]     pulEncryptedLen ���ܽ���ĳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_EncryptFinal(HANDLE hKey,BYTE * pbEncryptedData,ULONG * pulEncryptedLen);
/**
* @brief ���ܳ�ʼ��
* @note  �����������������ݽ��ܵ��㷨��ز���
*        
* @param[IN]      hKey         ������Կ�����
* @param[IN]      EncryptParam ������Կ�㷨��ز�����
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_DecryptInit(HANDLE hKey,BLOCKCIPHERPARAM EncryptParam);
/**
* @brief �������ݽ���
* @note  ������������һ�������ݵĽ��ܲ������ڵ���SKF_Decrypt֮ǰ�����ȵ���SKF_DecryptInit��ʼ����
*        
* @param[IN]      hKey            ������Կ�����
* @param[IN]      pbEncryptedData ���������ݡ�
* @param[IN]      ulEncryptedLen  ���������ݳ��ȡ�
* @param[OUT]     pbData          ���ܺ�����ݻ�����������ΪNULL�����ڻ�ü��ܺ����ݳ��ȡ�
* @param[IN,OUT]  pulDataLen      ����ʱ��ʾ���������ȣ����ʱ��ʾ�������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_Decrypt(HANDLE hKey,BYTE * pbEncryptedData,ULONG ulEncryptedLen,BYTE * pbData,ULONG * pulDataLen);
/**
* @brief �������ݽ���
* @note  �����������Զ���������ݽ��н��ܡ��ڵ���SKF_DecryptUpdate֮ǰ�����ȵ���SKF_DecryptInit���ڵ���SKF_DecryptUpdate֮�󣬱������SKF_DecryptFinal��
*        
* @param[IN]      hKey            ������Կ�����
* @param[IN]      pbEncryptedData ���������ݡ�
* @param[IN]      ulEncryptedLen  ���������ݳ��ȡ�
* @param[OUT]     pbData          ���ܺ�����ݻ�����ָ�롣
* @param[IN,OUT]  pulDataLen      ����ʱ��ʾ���������ȣ����ʱ��ʾ�������ʵ�ʳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_DecryptUpdate(HANDLE hKey,BYTE * pbEncryptedData,ULONG ulEncryptedLen,BYTE * pbData,ULONG * pulDataLen);
/**
* @brief �����������Ľ���
* @note  �����������ȵ���SKF_DecryptInit��ʼ�����ܲ������ٵ���SKF_DecryptUpdate�Զ��������н��ܣ�������SKF_DecryptFinal��������������ݵĽ��ܡ�
*        
* @param[IN]      hKey                ������Կ�����
* @param[OUT]     pbDecryptedData     ָ����ܽ���Ļ�����������˲���ΪNULLʱ����pulDecryptedDataLen���ؽ��ܽ���ĳ���
* @param[IN,OUT]  pulDecryptedDataLen ����ʱ��ʾ���������ȣ����ʱ��ʾ���ܽ�����ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_DecryptFinal(HANDLE hKey,BYTE * pbDecryptedData,ULONG * pulDecryptedDataLen);
/**
* @brief �����Ӵճ�ʼ��
*        
* @param[IN]      hDev        �豸�����
* @param[IN]      ulAlgID     �����Ӵ��㷨��ʶ��
* @param[IN]      pPubKey     ǩ���߹�Կ����ulAlgIDΪSGD_SM3ʱ��Ч��
* @param[IN]      pucID       ǩ����IDֵ����ulAlgIDΪSGD_SM3ʱ��Ч��
* @param[IN]      ulIDLen     ǩ����ID�ĳ��ȡ���ulAlgIDΪSGD_SM3ʱ��Ч��
* @param[OUT]     phHash      �����Ӵն������� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ��ulAlgIDΪSGD_SM3��ulIDLen��Ϊ0������£�pPubKey��pucID��Ч��ִ��SM2�㷨ǩ��Ԥ����1������
*/
ULONG DEVAPI SKF_DigestInit(DEVHANDLE hDev,ULONG ulAlgID,PECCPUBLICKEYBLOB pPubKey, unsigned char * pucID, ULONG ulIDLen,HANDLE * phHash);
/**
* @brief �������������Ӵ�
* @note  �����������Ե�һ�������Ϣ���������Ӵռ��㡣����SKF_Digest֮ǰ�������SKF_DigestInit��ʼ����
*        
* @param[IN]      hHash        �Ӵն�����
* @param[IN]      pbData       ָ����Ϣ���ݵĻ�����
* @param[IN]      ulDataLen    ��Ϣ���ݵĳ���
* @param[OUT]     pbHashData   �Ӵ����ݻ�����ָ�룬���˲���ΪNULL ʱ����pulHashLen�����Ӵս���ĳ���
* @param[IN,OUT]  pulHashLen   ����ʱ��ʾpbHashData �������ĳ��ȣ������Ӵս���ĳ���
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ���� SKF_Digest ֮ǰ��������� SKF_DigestInit ��ʼ���Ӵռ��������SKF_Digest�ȼ��ڶ�ε��� SKF_DigestUpdate ֮���ٵ��� SKF_DigestFinal��
*/
ULONG DEVAPI SKF_Digest(HANDLE hHash,BYTE * pbData,ULONG ulDataLen,BYTE * phHashData,ULONG * pulHashLen);
/**
* @brief �������������Ӵ�
* @note  �����������Զ���������ݽ��������Ӵ����㡣����SKF_DigestUpdate֮ǰ�������SKF_DigestInit������SKF_DigestUpdate֮��������SKF_DigestFinal��
*        
* @param[IN]      hHash        �����Ӵն�������
* @param[IN]      pbData       ָ����Ϣ���ݵĻ�������
* @param[IN]      ulDataLen    ��Ϣ���ݵĳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ���� SKF_DigestUpdate ֮ǰ��������� SKF_DigestInit ��ʼ���Ӵռ������������ SKF_DigestUpdate ֮�󣬱������SKF_DigestFinal �����Ӵռ��������
*/
ULONG DEVAPI SKF_DigestUpdate(HANDLE hHash,BYTE * pbData,ULONG ulDataLen);
/**
* @brief ���������Ӵ�
* @note  ���������������������������Ӵռ��㣬��������浽ָ���Ļ�������
*        
* @param[IN]      hHash        �����Ӵն�������
* @param[OUT]     pHashData    ���ص������Ӵս��������ָ�룬����˲���ΪNULL����pulHashLen�����Ӵս�����ȡ�
* @param[IN,OUT]  pulHashLen   ����ʱ��ʾ���������ȣ����ʱ��ʾ�����Ӵս���ĳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark SKF_DigestFinal �������� SKF_DigestUpdate ֮��
*/
ULONG DEVAPI SKF_DigestFinal(HANDLE hHash,BYTE * pHashData,ULONG * pulHashLen);
/**
* @brief ��Ϣ�����������ʼ��
* @note  ������������ʼ����Ϣ�����������������ü�����Ϣ���������Կ��������������Ϣ����������
*        
* @param[IN]      hKey       ������Ϣ���������Կ�����
* @param[IN]      pMacParam  ��Ϣ��֤������ز�����������ʼ��������ʼ�������ȡ���䷽���ȡ� 
* @param[OUT]     phMac      ��Ϣ�������������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ��Ϣ�����������÷�������㷨�� CBC ģʽ�������ܽ�������һ����Ϊ�����������������ݵĳ��ȱ����Ƿ�������㷨�鳤�ı������ӿ��ڲ�����������䡣
*/
ULONG DEVAPI SKF_MacInit(HANDLE hKey, BLOCKCIPHERPARAM * pMacParam, HANDLE * phMac); 
/**
* @brief ����������Ϣ����������
* @note  ����������SKF_Mac ���㵥һ�������ݵ���Ϣ�����롣
*        
* @param[IN]      hMac       ��Ϣ����������
* @param[IN]      pbData     ָ����������ݵĻ������� 
* @param[IN]      ulDataLen  ���������ݵĳ��ȡ�
* @param[OUT]     pbMacData  ָ������� Mac ���������˲���Ϊ NULL ʱ���� pulMacLen���ؼ���� Mac ����ĳ��ȡ�
* @param[IN,OUT]  pulMacLen  ����ʱ��ʾ pbMacData �������ĳ��ȣ����ؼ��� Mac ����ĳ��ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ���� SKF_Mac ֮ǰ��������� SKF_MacInit ��ʼ����Ϣ��������������SKF_Mac�ȼ��ڶ�ε��� SKF_MacUpdate ֮���ٵ��� SKF_MacFinal��
*/
ULONG DEVAPI SKF_Mac(HANDLE hMac,BYTE * pbData,ULONG ulDataLen,BYTE * pbMacData, ULONG * pulMacLen);
/**
* @brief ����������Ϣ����������
* @note  �����������������������ݵ���Ϣ�����롣
*        
* @param[IN]      hMac       ��Ϣ����������
* @param[IN]      pbData     ָ����������ݵĻ������� 
* @param[IN]      ulDataLen  ���������ݵĳ��ȡ�
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark ���� SKF_MacUpdate ֮ǰ��������� SKF_MacInit ��ʼ����Ϣ������������������ SKF_MacUpdate ֮�󣬱������ SKF_MacFinal ��������������ݵ���Ϣ��������������
*/
ULONG DEVAPI SKF_MacUpdate(HANDLE hMac, BYTE * pbData,ULONG ulDataLen);
/**
* @brief ������Ϣ����������
* @note  ������������������������ݵ���Ϣ��������������
*        
* @param[IN]      hMac           ��Ϣ����������
* @param[OUT]     pbMacData      ָ����Ϣ������Ļ����������˲���Ϊ NULL ʱ����pulMacDataLen ������Ϣ�����뷵�صĳ��ȡ�  
* @param[OUT]     pulMacDataLen  ����ʱ��ʾ��Ϣ�����뻺��������󳤶ȣ�������Ϣ������ĳ��ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark SKF_MacFinal �������� SKF_MacUpdate ֮��
*/
ULONG DEVAPI SKF_MacFinal(HANDLE hMac,BYTE * pbMacData,ULONG * pulMacDataLen); 
/**
* @brief �ر����������
* @note  �����������رջỰ��Կ�������Ӵն���MAC����ECC��ԿЭ�̵Ⱦ��
*        
* @param[IN]      hHandle        Ҫ�رյĶ�������
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_CloseHandle(HANDLE hHandle);

/** 
* @brief ECC˽Կ���� 
*
* @param[IN] 	 hContainer     �������
* @param[IN] 	 dwKeySpec      ˽Կ���ͣ�1Ϊ����˽Կ��2Ϊǩ��˽Կ
* @param[IN] 	 pCipherText    �������ݽṹ
* @param[OUT] 	 pbData         ָ����ܽ���Ļ�����,���ֵΪNULL������ȡ�ý��ܺ����ݳ���
* @param[IN,OUT] pdwDataLen     ����ʱ��ʾpbData�ĳ��ȣ����ؽ������ݵĴ�С
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_PrvKeyDecrypt(HCONTAINER hContainer, DWORD dwKeySpec, PECCCIPHERBLOB pCipherText, BYTE *pbData, DWORD *pdwDataLen);

/** 
* @brief RSA˽Կ���� 
*
* @param[IN] 	 hContainer     �������
* @param[IN]     dwKeySpec      ˽Կ���ͣ�1Ϊ����˽Կ��2Ϊǩ��˽Կ
* @param[IN]     pbIn           �����ܵ�����
* @param[IN]     ulInLen        ���������ݵĳ���
* @param[OUT]    pbOut          ָ����ܽ���Ļ����������ֵΪNULL������ȡ�ý��ܺ����ݳ���
* @param[IN,OUT] pulOutLen      ����ʱ��ʾpbOut�ĳ��ȣ����ؽ������ݵĴ�С
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_RSADecrypt(HCONTAINER hContainer, DWORD dwKeySpec, BYTE *pbIn, ULONG  ulInLen, BYTE *pbOut, ULONG *pulOutLen);

/**
* @brief (����)����ECC��˽Կ�� (SKF��չ�ӿ�)   
*        
* @param[IN]      hContainer        ��Կ���������
* @param[IN]      bSignFlag         TRUE��ʾ����ǩ����Կ��FALSE��ʾ�������ܹ�Կ
* @param[IN]      pPubKey           ��Կ�ṹ(��32B��Ч)��
* @param[IN]      pPriKey           ˽Կ�ṹ(��32B��Ч)��
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*
* @remark Ȩ��Ҫ����Ҫ�û�Ȩ��
*/
ULONG DEVAPI SKF_ImportECCKeyPairEx(HCONTAINER hContainer, BOOL bSignFlag, PECCPUBLICKEYBLOB pPubKey, PECCPRIVATEKEYBLOB pPriKey);
/**
* @brief ECC���ڹ�Կ����(SKF��չ�ӿ�)
* @note   ��������:ʹ�ÿ���ECC ��Կ�������������������㲢��������
*        
* @param[IN]      hContainer      �����š�
* @param[IN]      bSignFlag       TRUE��ʾ����ǩ����Կ��FALSE��ʾ�������ܹ�Կ
* @param[IN]      pbPlainText     �����ܵ��������ݡ�
* @param[IN]      ulPlainTextLen  �����ܵ��������ݳ��ȡ�
* @param[OUT]     pCipherText     �������ݡ�    
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ECCEncrypt(HCONTAINER hContainer, BOOL bSignFlag, BYTE * pbPlainText, ULONG ulPlainTextLen, PECCCIPHERBLOB pCipherText);

/**
* @brief ECC����˽Կ����(SKF��չ�ӿ�)
* @note   ��������:ʹ�ÿ��ڴ���� ECC ˽Կ�������������������㲢��������
*        
* @param[IN]      hContainer      �����š�
* @param[IN]      bSignFlag       TRUE��ʾ����ǩ����Կ��FALSE��ʾ�������ܹ�Կ
* @param[IN]      pCipherText     �����ܵ��������ݡ�
* @param[OUT]     pbPlainText     �����������ݣ�����ò���Ϊ NULL������pulPlainTextLen �����������ݵ�ʵ�ʳ��ȡ�
* @param[IN,OUT]  pulPlainTextLen ����ǰ��ʾpbPlainText �������ĳ��ȣ������������ݵ�ʵ�ʳ��ȡ� 
*
* @retval SAR_OK:  �ɹ���
* @retval ������   �����롣
*/
ULONG DEVAPI SKF_ECCDecrypt(HCONTAINER hContainer, BOOL bSignFlag, PECCCIPHERBLOB pCipherText, BYTE* pbPlainText, ULONG* pulPlainTextLen);



#ifdef __cplusplus
}
#endif

#endif

