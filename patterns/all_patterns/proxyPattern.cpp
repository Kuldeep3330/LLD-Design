 #include <bits/stdc++.h>
using namespace std;

class Image
{
public:
    virtual void display() const = 0;
};
class RealImage : public Image
{
private:
    string filename;

public:
    RealImage(const string &filename) : filename(filename) {}
    void display() const override
    {
        cout << "Dispaly Image : " << filename << endl;
    }
};
// Proxy: control access to RealImage
class ProxyImage : public Image
{
private:
    string filename;
    string userRole;
    unique_ptr<RealImage> realImage;//RealImage *realImage;

public:
    ProxyImage(const string &filename, const string &userRole)
        : filename(filename), userRole(userRole) {}

    void display() const override
    {
        if (userRole == "Admin")
        {
            if (realImage == nullptr)
            {
                realImage == make_unique<RealImage>(filename);//realImage=new RealImage(filename);
            }
            else
            {
                realImage->display();
            }
        }
        else
        {
            cout << "Access denied\n";
        }
    }
};

int main()
{
    ProxyImage adminImage("high_res_image.png", "Admin");
    adminImage.display();
    return 0;
}