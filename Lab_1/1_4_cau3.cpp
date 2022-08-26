#include <stdio.h>
#include <string.h>
struct Date{
	int ngay,thang,nam;
};
struct HocSinh{
	int MS;
	char ten[20];
	Date NgaySinh;
};
void Nhap1HS(HocSinh &hs){
	printf("Ma so hoc sinh: "); scanf("%d", &hs.MS);
	fflush(stdin);
	printf("Ten hoc sinh: "); gets(hs.ten);
	printf("Ngay sinh (ngay/thang/nam): "); scanf("%d/%d/%d", &hs.NgaySinh.ngay, &hs.NgaySinh.thang, &hs.NgaySinh.nam);
}
void NhapDSHS(HocSinh hs[], int n){
	for(int i=0;i<n;i++){
		printf("\nHoc sinh thu %d\n", i+1);
		Nhap1HS(hs[i]);
	}
}
int SoSanhDate(Date a, Date b){
	if(a.ngay!=b.ngay) return 0;
	if(a.thang!=b.thang) return 0;
	if(a.nam!=b.nam) return 0;
	return 1;
}
int TimTheoMaSo(HocSinh hs[], int n, int x){
	for(int i=0;i<n;i++)
		if(hs[i].MS == x)
			return i;
	return -1;
}
int TimTheoNgaySinh(HocSinh hs[], int n, Date x){
	for(int i=0;i<n;i++)
		if(SoSanhDate(hs[i].NgaySinh, x))
			return i;
	return -1;
}
int TimTheoTen(HocSinh hs[], int n, char x[]){
	for(int i=0; i<n; i++)
		if(strcmp(hs[i].ten, x)==0)
			return i;
	return -1;
}
void XuatSV(HocSinh hs){
	printf("\nMa hoc sinh: %d", hs.MS);
	printf("\nHo va ten: %s", hs.ten);
	printf("\nNgay sinh: %d/%d/%d", hs.NgaySinh.ngay, hs.NgaySinh.thang, hs.NgaySinh.nam);
}
void XuatKQ(HocSinh hs[], int kq){
	if(kq!=-1)
		XuatSV(hs[kq]);
	else
		printf("\nKhong tim thay");
}
int main(){
	int n;
	printf("Nhap vao so luong hoc sinh: "); scanf("%d", &n);
	HocSinh hs[n];
	NhapDSHS(hs,n);
	int id;
	printf("\nNhap vao ma hs can tim: "); scanf("%d", &id);
	int kq = TimTheoMaSo(hs,n,id);
	XuatKQ(hs, kq);
	char name[20];
	fflush(stdin);
	printf("\nNhap vao ten hoc sinh can tim: "); gets(name);
	kq = TimTheoTen(hs,n,name);
	XuatKQ(hs, kq);
	Date x;
	printf("\nNhap vao ngay sinh can tim (ngay/thang/nam): ");
	scanf("%d/%d/%d", &x.ngay, &x.thang, &x.nam);
	kq= TimTheoNgaySinh(hs, n, x);
	XuatKQ(hs, kq);
	return 0;
}
