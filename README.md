Fractol projeniz için GitHub reposu için detaylı bir README.md yazmak oldukça önemli bir adım. Bu dosya, projeyi kullanacak kişilere projenin ne olduğunu, nasıl çalıştığını ve nasıl kullanacaklarını anlatmak için çok faydalı olacaktır. İşte örnek bir README.md dosyası:

markdown
Copy
Edit
# Fractol

Fractol, kullanıcıların farklı Fraktal görüntülerini oluşturabilmelerini sağlayan bir C programıdır. Proje, **Mandelbrot**, **Julia** ve **Burning Ship** gibi popüler fraktal setlerini görüntülemenize olanak tanır. Bu proje, grafikleri çizmek için **MiniLibX** kütüphanesini kullanır ve grafiksel arayüz üzerinden interaktif bir deneyim sunar.

## İçindekiler

- [Proje Hakkında](#proje-hakkında)
- [Başlangıç](#başlangıç)
  - [Gereksinimler](#gereksinimler)
  - [Kurulum](#kurulum)
  - [Kullanım](#kullanım)
- [Özellikler](#özellikler)
- [Lisans](#lisans)
- [Yazar](#yazar)

## Proje Hakkında

Fractol, fraktal setlerinin görselleştirilmesine odaklanan bir programdır. Kullanıcılar, çeşitli fraktalların parametrelerini ayarlayarak farklı desenler ve şekiller oluşturabilirler. Program, kullanıcının farenin hareketleri ve tuş kombinasyonları ile etkileşimli bir deneyim sunarak fraktalların detaylarını keşfetmesini sağlar.

Programın desteklediği başlıca fraktal türleri:
- **Mandelbrot Seti**
- **Julia Seti**
- **Burning Ship Seti**

## Başlangıç

### Gereksinimler

Fractol'u çalıştırmak için aşağıdaki yazılım ve kütüphaneler gereklidir:

- **MiniLibX**: Grafiksel arayüz için kullanılan kütüphane.
- **X11**: X11 sistemleri için grafiksel arayüz desteği.
- **gcc**: C kodunu derlemek için GCC derleyicisi.
- **Make**: Proje derlemeyi ve yönetmeyi sağlayan araç.

### Kurulum

Fractol'u kendi bilgisayarınızda çalıştırmak için aşağıdaki adımları takip edebilirsiniz:

1. **Depoyu Klonlayın:**

   ```bash
   git clone https://github.com/yourusername/fractol.git
   cd fractol
Gerekli Kütüphaneleri Yükleyin:

MiniLibX, genellikle X11 sistemlerinde kullanılır ve bu kütüphaneyi yüklemek için ilgili talimatları takip etmeniz gerekebilir. Örneğin, macOS kullanıcıları için:

bash
Copy
Edit
brew install minilibx
Linux kullanıcıları için ise şu komutlar yardımcı olabilir:

bash
Copy
Edit
sudo apt-get install libmlx-dev
sudo apt-get install xorg-dev
Projeyi Derleyin:

bash
Copy
Edit
make
Projeyi Çalıştırın:

bash
Copy
Edit
./fractol
Çalıştırdıktan sonra, fraktal görselleştirmesini görebileceğiniz bir pencere açılacaktır.

Kullanım
Fractol programını çalıştırdığınızda, ana pencere üzerinde şu etkileşimleri gerçekleştirebilirsiniz:

Mandelbrot Seti: 1 tuşuna basarak Mandelbrot setini görüntüleyebilirsiniz.

Julia Seti: 2 tuşuna basarak Julia setini görüntüleyebilirsiniz.

Burning Ship Seti: 3 tuşuna basarak Burning Ship setini görüntüleyebilirsiniz.

Kullanıcılar, fareyi kullanarak fraktalların parametrelerini değiştirebilir ve görüntüleri yakınlaştırıp uzaklaştırabilirler.

Parametre Ayarları
Fractol, kullanıcıların fraktalların görünümünü değiştirebileceği birkaç önemli parametreyi içerir:

Zoom: Mouse scroll ile fraktalları yakınlaştırabilir veya uzaklaştırabilirsiniz.

Renk: Renk paletini değiştirmek için yön tuşlarını kullanabilirsiniz.

Fraktal Sınırları: Çeşitli setlerin parametrelerini fare ile tıklayarak değiştirebilirsiniz.

Klavye Kısayolları
Esc: Programı kapatır.

Arrows: Fraktal renklerini değiştirmek için kullanılır.

W/A/S/D: Fraktal görüntüsünü hareket ettirir.

Özellikler
Birden fazla fraktal türü: Mandelbrot, Julia, Burning Ship gibi popüler fraktal setlerini görüntüleme.

Kullanıcı etkileşimi: Fare hareketleri ve tuş kombinasyonları ile fraktal parametrelerini değiştirme.

Grafiksel görselleştirme: MiniLibX kullanılarak yüksek kaliteli görselleştirmeler.

Yüksek çözünürlük desteği: Farklı çözünürlüklerde fraktal görselleştirmelerini görüntüleme.

Lisans
Bu proje, MIT Lisansı altında lisanslanmıştır.

Yazar
Bu proje, Adınız tarafından yazılmıştır.

markdown
Copy
Edit

Bu `README.md` dosyası, hem Fractol'un amacını anlatır hem de projeyi kullanmak ve gel
