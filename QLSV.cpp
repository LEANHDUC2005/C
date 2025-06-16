#include <stdio.h>
#include <string.h>
#define MAX 200

// 1. KHAI BAO DU LIEU
typedef struct {
    char mssv[10];
    char hoten[50];
    char sdt[15];
    char gioitinh[5];
    char ngaysinh[15];
    char malop[10];
    float diemtrungbinh;
} Sinhvien;


// +------CAC HAM CHUC NANG-------+
void nhapChuoi(char str[],int size);
void nhap(Sinhvien a[MAX], int n);
void xuat(Sinhvien a[MAX], int n);
int TimKiemTheoMSSV(Sinhvien a[MAX], int n, char MSSVCanTim[]);
int TimKiemTheoHoTen(Sinhvien a[MAX], int n, char TenCanTim[]);
int TimKiemTheoSDT(Sinhvien a[MAX], int n, char SDTCanTim[]);
void ThemSinhVien(Sinhvien a[MAX], int *n);
void XoaSinhVien(Sinhvien a[MAX], int *n, char MSSVCanXoa[]);
void SapXepDTBTangDan(Sinhvien a[MAX],int n);
void SapXepDTBGiamDan(Sinhvien aMAX[],int n);
void CapNhatSinhVien(Sinhvien a[MAX], int n, char MSSVCanCapNhat[]);
void KetQuaTimKiem(Sinhvien a[MAX],int i);
void DocFile(Sinhvien a[MAX]);
void GhiFile(Sinhvien a[MAX], int n);


// +-----DINH NGHIA CAC HAM CHUC NANG-----+
// Ham nhap chuoi 
void nhapChuoi(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa '\n'
}

// 2. HAM NHAP THONG TIN
void nhap(Sinhvien a[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien so %d\n", i + 1);

        printf("Ma so sinh vien: ");
        fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi 
        nhapChuoi(a[i].mssv, sizeof(a[i].mssv));

        printf("Ho va ten: ");
        nhapChuoi(a[i].hoten, sizeof(a[i].hoten));

        printf("So dien thoai: ");
        nhapChuoi(a[i].sdt, sizeof(a[i].sdt));

        printf("Gioi tinh: ");
        nhapChuoi(a[i].gioitinh, sizeof(a[i].gioitinh));

        printf("Ngay sinh: ");
        nhapChuoi(a[i].ngaysinh, sizeof(a[i].ngaysinh));

        printf("Ma lop: ");
        nhapChuoi(a[i].malop, sizeof(a[i].malop));

        printf("Diem trung binh: ");
        scanf("%f", &a[i].diemtrungbinh);
        getchar(); // Doc ky tu Enter
    }
}

// 3. IN DANH SACH
void xuat(Sinhvien a[MAX], int n) {
    printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
           "STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
    printf("---------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6.2f\n",
               i + 1,
               a[i].mssv,
               a[i].hoten,
               a[i].sdt,
               a[i].gioitinh,
               a[i].ngaysinh,
               a[i].malop,
               a[i].diemtrungbinh);
    }
}

// 4. HAM TIM KIEM
// a.Tim kiem theo MSSV
int TimKiemTheoMSSV(Sinhvien a[MAX], int n, char MSSVCanTim[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].mssv, MSSVCanTim) == 0)
            return i;
    }
    return -1;
}
// b.Tim kiem theo HoTen
int TimKiemTheoHoTen(Sinhvien a[MAX], int n, char TenCanTim[]) {
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].hoten, TenCanTim) != NULL)
            return i;
    }
    return -1;
}
// c.Tim kiem theo SoDienThoai
int TimKiemTheoSDT(Sinhvien a[MAX], int n, char SDTCanTim[]) {
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].sdt, SDTCanTim) != NULL)
            return i;
    }
    return -1;
}
// d.In ra ket qua tim kiem
void KetQuaTimKiem(Sinhvien a[MAX], int i)
{
	if(i == -1)	
	{
		printf("Khong tim thay sinh vien");
	}
	else
	{
	printf("----------------------------------DA TIM THAY SINH VIEN !-------------------------------------------\n");
    printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
           "STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("%-4d | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6.2f\n",
               i + 1,
               a[i].mssv,
               a[i].hoten,
               a[i].sdt,
               a[i].gioitinh,
               a[i].ngaysinh,
               a[i].malop,
               a[i].diemtrungbinh);
    }
}

// 5. THEM SINH VIEN
// Kiem tra so luong sinh vien -> Nhap thong tin sinh vien can them -> Tang bien dem n (*n) hay So Thu Tu
void ThemSinhVien(Sinhvien a[MAX], int *n) {
    if (*n >= MAX) {  //Kiem tra So luong sinh vien so voi gioi han
        printf("Danh sach da day, khong the them sinh vien!\n");
        return;
    }

    printf("\n--- Nhap thong tin sinh vien moi ---\n");
    printf("-- Sinh vien so: %d\n", *n + 1);

    printf("Ma so sinh vien: ");
    fflush(stdin);
    nhapChuoi(a[*n].mssv, sizeof(a[*n].mssv));

    printf("Ho va ten: ");
    nhapChuoi(a[*n].hoten, sizeof(a[*n].hoten));

    printf("So dien thoai: ");
    nhapChuoi(a[*n].sdt, sizeof(a[*n].sdt));

    printf("Gioi tinh: ");
    nhapChuoi(a[*n].gioitinh, sizeof(a[*n].gioitinh));

    printf("Ngay sinh: ");
    nhapChuoi(a[*n].ngaysinh, sizeof(a[*n].ngaysinh));

    printf("Ma lop: ");
    nhapChuoi(a[*n].malop, sizeof(a[*n].malop));

    printf("Diem trung binh: ");
    scanf("%f", &a[*n].diemtrungbinh);
    while (getchar() != '\n'); //  Xoa ky tu thua trong buffer
    
    (*n)++;
    
    printf("+----Da them thanh cong sinh vien----+\n");
}

// 6. XOA SINH VIEN
void XoaSinhVien(Sinhvien a[MAX], int *n, char MSSVCanXoa[MAX]) {
    int i = TimKiemTheoMSSV(a, *n, MSSVCanXoa);
    if (i == -1) {
        printf("Khong tim thay sinh vien co MSSV [%s] de xoa\n", MSSVCanXoa);
        return;
    }
    for (int j = i; j < *n - 1; j++) {
        a[j] = a[j + 1];                 // Ghi de sinh vien vi tri j xoa bang sinh vien vi tri j + 1
    }
    (*n)--;
    printf("+---Da xoa sinh vien thanh cong---+\n");
}

// 7. CAP NHAT THONG TIN SINH VIEN
void CapNhatSinhVien(Sinhvien a[MAX], int n, char MSSVCanCapNhat[]) {
    int i = TimKiemTheoMSSV(a, n, MSSVCanCapNhat);
    if (i == -1) {
        printf("Khong tim thay sinh vien co MSSV [%s] de cap nhat\n", MSSVCanCapNhat);
        return;
    }
    else{
    printf("\n--- Thong tin hien tai ---\n");
    printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
           "STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("%-4d | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6.2f\n",
               i + 1,
               a[i].mssv,
               a[i].hoten,
               a[i].sdt,
               a[i].gioitinh,
               a[i].ngaysinh,
               a[i].malop,
               a[i].diemtrungbinh);

    printf("\n--- Nhap thong tin moi ---\n");

    printf("Ma so sinh vien: ");
    fflush(stdin);
    nhapChuoi(a[i].mssv, sizeof(a[i].mssv));

    printf("Ho va ten: ");
    nhapChuoi(a[i].hoten, sizeof(a[i].hoten));

    printf("So dien thoai: ");
    nhapChuoi(a[i].sdt, sizeof(a[i].sdt));

    printf("Gioi tinh: ");
    nhapChuoi(a[i].gioitinh, sizeof(a[i].gioitinh));

    printf("Ngay sinh: ");
    nhapChuoi(a[i].ngaysinh, sizeof(a[i].ngaysinh));

    printf("Ma lop: ");
    nhapChuoi(a[i].malop, sizeof(a[i].malop));

    printf("Diem trung binh: ");
    scanf("%f", &a[i].diemtrungbinh);
    getchar();

    printf("+----Da cap nhat thanh cong thong tin sinh vien----+\n");
    }
}
// 8. HAM SAP XEP DANH SACH THEO 2 TIEU CHI: TANG/GIAM THEO DIEM VA THEO TEN TU A DEN Z
// a. Su dung thuat toan sap xep Interchange Sort cho Ham sap xep Diem trung binh TANG DAN
void SapXepDTBTangDan(Sinhvien a[MAX],int n)
{
	for(int i = 0; i < n-1 ; i++)
	{
		for(int j = i+1; j < n ;j++)
		{
			if ( a[i].diemtrungbinh > a[j].diemtrungbinh )
			{
				Sinhvien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
// b.Su dung thuat toan sap xep Bubble Sort cho sap xep Diem trung binh GIAM DAN
void SapXepDTBGiamDan(Sinhvien a[MAX],int n)
{
	for(int i=0; i<n; i++)   
	{
		for(int j=n-1; j>i; j--)
		{
			if(a[j].diemtrungbinh > a[j-1].diemtrungbinh)
			{
				Sinhvien temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
//. GHI DU LIEU RA TEP
void GhiFile(Sinhvien a[MAX],int n)
{
	FILE *f = fopen("sinhvien.txt", "w");  // w = write : Mo file de ghi gu lieu 
	if (f == NULL)
	{
		printf("Khong the mo tep de ghi\n");
		return;
	}
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s|%s|%s|%s|%s|%s|%.2f\n",
                a[i].mssv,
                a[i].hoten,
                a[i].sdt,
                a[i].gioitinh,
                a[i].ngaysinh,
                a[i].malop,
                a[i].diemtrungbinh);
    }

    fclose(f);
    printf("Da ghi %d sinh vien vao tep!\n", n);
}
//. DOC DU LIEU RA TEP 
void DocFile(Sinhvien a[MAX]) 
    {
    FILE *f = fopen("sinhvien.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc\n");
        return ;
    }

    int i = 0;
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
                  a[i].mssv,
                  a[i].hoten,
                  a[i].sdt,
                  a[i].gioitinh,
                  a[i].ngaysinh,
                  a[i].malop,
                  &a[i].diemtrungbinh) == 7) {
        i++;
    }

    fclose(f);
    printf("Da doc %d sinh vien tu tep!\n", i); // tra ve so luong sinh vien thuc te doc duoc
}
                

// MAIN
int main() {
    int n;
    printf("\n+----------- HE CO SO DU LIEU QUAN LY SINH VIEN -----------+\n");
    printf("Nhap so sinh vien [Toi da 100]: ");
    scanf("%d", &n);
    getchar();
    Sinhvien a[MAX];

    // Su dung ham chuc nang
    int i;
    do
	{
    printf("\n[+].Danh sach chuc nang:\n");
    printf("[0]:Nhap thong tin sinh vien\n");
    printf("[1].Them sinh vien\n");
    printf("[2].Hien thi danh sach sinh vien\n");
    printf("[3].Tim kiem sinh vien\n");
    printf("[4].Xoa sinh vien\n");
    printf("[5].Cap nhat thong tin sinh vien\n");
    printf("[6].Sap xep danh sach sinh vien\n");
    printf("[7].Ghi du lieu ra tep\n");
    printf("[8].Doc du lieu tu tep\n");
    printf("[9].Thoat\n");
    printf("\n");
    printf("Chon chuc nang [1-9]: ");
    scanf("%d",&i);
    getchar(); // Xóa bo nho dem sau khi scanf
	switch(i)
	{
		case 0: nhap(a, n);
                xuat(a, n);
		case 1: ThemSinhVien(a,&n);break;           // Them sinh vien
		case 2: xuat(a,n);break;                   // Hien thi danh sach sinh vien
		case 3:                                    // Tim kiem sinh vien
		{
				int search;                        
		        printf("\n---Chon phuong thuc tim kiem---\n");         // Tim kiem theo MSSV, Ho Ten hay So dien thoai
		        printf("[1].Tim theo MSSV\n");
		        printf("[2].Tim theo Ho Ten\n");
		        printf("[3].Tim theo So dien thoai\n");
		        printf("[1-3]: ");
		        scanf("%d",&search);
		        int vitri;            //Khai bao vi tri cua sinh vien tim kiem duoc
		        char GiaTriTimKiem[30];  // MSSV, HoTen hoac SDT can tim 
		        switch(search)
		        {
		        	case 1:
					{                                            // Day can phai la gia tri hang so 'a' khong phai ten bien a
					printf("Nhap MSSV cua sinh vien can tim: ");
					fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
					nhapChuoi(GiaTriTimKiem, sizeof(GiaTriTimKiem));
					vitri = TimKiemTheoMSSV(a, n, GiaTriTimKiem);
					KetQuaTimKiem(a, vitri);
				    }
					break;
					case 2:
				    {
					printf("Nhap Ho va Ten cua sinh vien can tim:");
					fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
					nhapChuoi(GiaTriTimKiem, sizeof(GiaTriTimKiem));
                    vitri = TimKiemTheoHoTen(a, n, GiaTriTimKiem);
					KetQuaTimKiem(a, vitri);
				    }
                    break;
					case 3:
					{
					printf("Nhap So dien thoai cua sinh vien can tim:");
					fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
					nhapChuoi(GiaTriTimKiem, sizeof(GiaTriTimKiem));
					vitri = TimKiemTheoSDT(a, n, GiaTriTimKiem);
					KetQuaTimKiem(a, vitri);
					}
					break;	
					default:
						printf("Lua chon khong hop le!\n");
				}
				break;
		}
		case 4:                                   // Xoa sinh vien
	    {
	    	char MSSVCanXoa[10];
	    	printf("Nhap MSSV cua sinh vien can xoa:");
	    	fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
	    	nhapChuoi(MSSVCanXoa, sizeof(MSSVCanXoa));
	    	XoaSinhVien(a, &n, MSSVCanXoa);
		}
		break;
		case 5:                                   // Cap nhat thong tin sinh vien
		{
			char MSSVCapNhat[10];
			printf("Nhap MSSV cua sinh vien can cap nhat:");
			fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
			nhapChuoi(MSSVCapNhat, sizeof(MSSVCapNhat));
			CapNhatSinhVien(a, n, MSSVCapNhat);	
		}
		break;
		case 6:                                   // Sap xep danh sach sinh vien
		{
			char choice;                           // Chon sap xep theo DTB tang dan hay giam dan
			printf("\n---Chon phuong thuc sap xep---\n");
			printf("[U].Sap xep theo diem trung binh tang dan\n");
			printf("[D].Sap xep theo diem trung binh giam dan\n");
			printf("[U-D]:");
			scanf("%c",&choice);
			switch(choice)
			{
				case 'U':                         // Sap xep theo diem trung binh tang dan
					{
						SapXepDTBTangDan(a, n);
						printf("\n------------------Danh sach sinh vien sap xep theo diem trung binh tang dan-----------------------\n");
						xuat(a,n);
					}
					break;
				case 'D':                         // Sap xep theo diem trung binh giam dan
					{
						printf("\n------------------Danh sach sinh vien sap xep theo diem trung binh giam dan-----------------------\n");
						SapXepDTBGiamDan(a,n);
						xuat(a,n);
					}
					break;
				default:
					printf("Lua chon khong hop le !\n");
		    }		
		}
		break;
		case 7:  GhiFile(a,n);break;              // Ghi du lieu ra tep
		case 8:  DocFile(a);break;                // Doc du lieu tu tep
		case 9: break;                
		default: printf("Lua chon khong hop le !\n");			        
    }
    }
    while(i != 9);
	printf("=== Ket thuc chuong trinh quan ly sinh vien ===\n");
    return 0;
}

