#MarkMyHTML
###The Following Tutorial Covers the Markdown Format Used in this Documentation Engine
##Paragraphs
Paragraphs are seperated by line breaks. A single line break **will not** make 
a new paragraph; there must be a visible space between the text blocks.
```
This will be the first
paragraph. Notice that
the line breaks make no difference.

This will be the second paragraph.
The double line break constructs a
seperate paragraph.
```
##Headings
A heading is like the title and subtitles of your document. There are six 
heading sizes. The size of your heading is determined by the amount of `#` 
put before the text.

For example, to construct the largest heading, you
would use `#This is the Largest Heading Availible` Likewise, you can construct
the smallest heading with `######This is the Smallest Heading Availibe`.
#This is the Largest Heading
##This is the Second Largest Heading
###This is the Third Largest Heading
####This is the Third Smallest Heading
#####This is the Second Smallest Heading
######This is the Smallest Heading
##Blockquotes
A blockquote is make by inserting a `>` before the text.
```
> This is a blockquote. It is often used for long quotes that wouldn't be suitable on a single line.
```
##Lists
A list can be unordered or ordered. An ordered list contains numbers next to 
each of its *list items*, an unordered list is marked by a `-` or `*` next to 
each item.
```
* Unordered lists are used in places where the order of the list items isn't important.
* It doesn't matter which symbol you use to create your list.

1. Ordered list's orders are important.
2. Ordered list's items often represent a sequence of instructions.
```
##Inlines
An inline is a monospaced piece of text that retains its formatting. 
(i.e. All spaces are preserved.) It's delimited by text contained between
__insert__.
An inline looks like `import gravity`.
##Blocks
A block is a mulitline section that preserves formatting. You can create a
block with __insert__.

A block looks like 
```
public class Screen
    implements Serializable {
  private int width, height;
  private volatile JFrame frame;

  public Screen() {
    this.width = Device.getWidth();
    this.height = Device.getHeight();
  }
}
```
##Links
You can create links in your documentation (relative or absolute) with the
syntax `[Description](url)`. For example, `[Updated Documentation](http://siliconincorporated.us/markmyhtml/documentation)`.