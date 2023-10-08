# Minishell Projesi

Minishell projesi, 42 okulu müfredatının en zorlayıcı ve keyifli projelerinden biridir. Bu projede bir dizi test durumuyla başa çıkmak ve yazılım mimarisi, sistem çağrıları, dosya tanımlayıcıları gibi birçok konuyu öğrenmek zorunda kalırsınız. Aynı zamanda takım koordinasyonu, yönetimi ve iş bölümü gibi yeteneklerinizi de geliştirebilirsiniz.

Minishell, bash kabuğunu taklit eden bir komut satırı yorumlayıcısı (shell) oluşturmanızı gerektirir. Projenin amacı, bash'ın temel işlevselliğini içermekle birlikte, bazı temel özellikleri gerçekleştirmektir.

## Kullanım

Projeyi kullanmak oldukça basittir. İlk olarak, `make` komutunu kullanarak `minishell` yürütülebilir dosyasını oluşturmanız gerekmektedir. Ardından aşağıdaki komutla programı başlatabilirsiniz:

```bash
./minishell
```

## Özellikler ve İşlevler

Minishell, aşağıdaki temel işlevselliği içermelidir:

- Minishell sadece etkileşimli modda çalışır (betikler desteklenmez, yani yürütülebilir dosya argümanı alamaz).
- Mutlak, göreli veya çevresel PATH'den (örneğin, /bin/ls veya sadece ls gibi) basit komutları çalıştırabilirsiniz.
- Komutları, argümanlar ve seçeneklerle birlikte çalıştırabilirsiniz.
- Çalıştırılan komutların geçmişini (yukarı/aşağı ok tuşlarıyla) görüntüleyebilirsiniz.
- Boruları (`|`) ve yönlendirmeleri (`<`, `>`, `>>`) kullanabilirsiniz.
- İşaretleme yapabilirsiniz (`""` ve `''` ile özel karakterlerden kaçınmak için).
- Çevre değişkenlerini (örneğin, `$HOME`) ve dönüş kodunu (`$?`) kullanabilirsiniz.
- Sinyalleri (Ctrl-C, Ctrl-\, Ctrl-D gibi) işleyebilirsiniz.

Ayrıca, aşağıdaki yerleşik işlevleri uygulamalısınız:

- echo
- exit
- env
- export
- unset
- cd
- pwd

## Proje Geliştirme

Bu projenin geliştirilmesi iki ana bölüme ayrılabilir: ayrıştırma ve yürütme.

- Ayrıştırma
Kullanıcı girdilerini işlemek ve komutları ayrıştırmak için gereklidir. Bu aşamada kullanıcı girdisi tokenlere ayrılır ve bir sözdizimi ağacı (syntax tree) veya soyut sözdizimi ağacı (AST) oluşturulur. Ayrıştırma, özel bir dil grameri kullanılarak yapılır.

- Yürütme
Minishell'in yürütme aşaması, kullanıcı komutlarını gerçek dünyada yürütmek için gereklidir. Bu aşama, komutların dosya tanımlayıcılarını yönetme, süreçleri çoğaltma ve komutları gerçekleştirme işlemlerini içerir.

    --Dosya Tanımlayıcıları Yönetimi: Yürütme sırasında, komutların giriş ve çıkışını yönlendirmek için dosya tanımlayıcıları kullanılır. Dosya tanımlayıcılarının uygun şekilde açılması, yönlendirilmesi ve kapatılması gereklidir.

    --Süreçlerin Çoğaltılması: Bazı komutlar, arka planda çalışan yeni süreçlerin oluşturulmasını gerektirebilir. Bu süreçler, ana programdan bağımsız olarak çalışır ve sonuçları ana programla paylaşır.

    --Komutların Gerçekleştirilmesi: AST veya sözdizimi ağacı, hangi komutların ve işlemlerin gerçekleştirileceğini belirler. Bu, kullanıcının verdiği komutların işlenmesi, sonuçlarının alınması ve gerektiğinde kullanıcının önüne sunulması anlamına gelir.

    --Minishell'in yürütme aşaması, kullanıcı komutlarını sistemin anlayabileceği bir şekilde çevirir ve bu komutları işletim sistemi üzerinde çalıştırır. Bu, kullanıcının istediği işlemleri gerçekleştirmesini sağlar.

## Proje Zorlukları

Bu projenin geliştirilmesi sırasında bazı zorluklarla karşılaşabilirsiniz. Özellikle işaretleme, boru hattı işlemleri ve dosya yönlendirmeleri gibi konular karmaşık olabilir. Ayrıca, yerleşik işlevlerin doğru bir şekilde çalıştığından emin olmak için özen göstermelisiniz.

Proje geliştirme aşamasında, işbirliği yaptığınız takım üyeleriyle uyum içinde çalışmak ve işleri etkili bir şekilde dağıtmak önemlidir.

Umarım bu README belgesi, Minishell projesini anlama ve başarıyla tamamlama sürecinize yardımcı olur. Başarılar dilerim!
